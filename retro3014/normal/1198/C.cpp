#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 100000;

int T;
int N, M;
vector<pii> gp[3 * MAX_N+1];
bool chk[3 * MAX_N+1];
vector<int> edge;


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=0; i<M; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			gp[a].pb({b, i+1}); gp[b].pb({a, i+1});
		}
		for(int i=1; i<=N*3; i++){
			if(chk[i])	continue;
			for(pii j : gp[i]){
				if(!chk[j.first]){
					edge.pb(j.second);
					chk[i] = true;
					chk[j.first] = true;
					break;
				}
			}
		}
		if(edge.size()>=N){
			printf("Matching\n");
			for(int i=0; i<N; i++){
				printf("%d ", edge[i]);
			}
			printf("\n");
		}else{
			printf("IndSet\n");
			int cnt = 0;
			for(int i=1; i<=3 * N; i++){
				if(!chk[i]){
					printf("%d ", i);
					cnt++;
					if(cnt==N)	break;
				}
			}
			printf("\n");
		}
		for(int i=1; i<=3 * N; i++){
			chk[i] = false;
		}
		while(!edge.empty())	edge.pop_back();
		for(int i=1; i<=3 * N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
		}

		
	}

	return 0;
}