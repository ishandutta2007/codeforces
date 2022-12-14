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

const int MAX_N = 200000;

int N;
vector<int> a, b;
int cnt[MAX_N+1];
bool A[MAX_N+1];

int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		a.pb(x);
		if(x>0){
			cnt[x] = 0;
		}
	}for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		b.pb(x);
		if(x>0){
			cnt[x] = i+1;
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		int t = N - i;
		ans = max(ans, t + cnt[i]+1);
		//cout<<t+cnt[i]<<endl;
	}
	if(b[N-1]!=0){
		int idx = N-1;
		bool tf = true;
		for(int t = b[N-1]; t>0; t--){			
			if(b[idx]!=t){
				tf = false;
				break;
			}
			idx--;
		}
		if(tf){
			for(int i=0 ;i<N; i++){
				A[a[i]] = true;
			}
			for(int i=b[N-1]+1; i<=N; i++){
				if(A[i]==false){
					tf = false;
					break;
				}
				A[b[i-(b[N-1]+1)]] = true;
			}
			if(tf){
				ans = min(ans, N - b[N-1]);
			}
		}
	}
	cout<< ans;
	return 0;
}