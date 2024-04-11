#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
vector<int> A[330];
vector<pii> V;
int T[101010];

void upd(int k){while(k<=N*M)T[k]++,k+=k&-k;}
int f(int k){int r=0; while(k)r+=T[k],k^=k&-k; return r;}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		for (int i=0; i<N; i++) A[i].clear(), A[i].resize(M+1);
		V.clear();
		for (int i=1; i<=N*M; i++){
			int a;
			scanf("%d", &a);
			V.pb(pii(a, i));
		}
		sort(V.begin(), V.end());
		int t=0;
		for (int i=0; i<N; i++){
			for (int j=0; j<M; j++){
				if (V[i*M+j].fi == V[t].fi) continue;
				else{
					for (int k=0; k<=i*M+j-1-t; k++){
						A[i][j-1-k] = V[t+k].se;
					}
					t = i*M+j;
				}
			}
			if (t < (i+1)*M){
				for (int k=0; k<=(i+1)*M-1-t; k++){
					A[i][M-1-k] = V[t+k].se;
				}
				t = (i+1)*M;
			}
		}
		LL ans=0;
		for (int i=0; i<N; i++){
			for (int j=1; j<=N*M; j++) T[j] = 0;
			for (int j=0; j<M; j++){
				ans += f(A[i][j]);
				upd(A[i][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}