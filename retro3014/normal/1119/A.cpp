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

int N;
vector<int> C;
int ans;
int c1, c2;
int x1, x2;

int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		C.pb(x);
		if(c1==0){
			c1 = x;
			x1 = i;
		}else if(x!=c1 && c2==0){
			c2 = x;
			x2 = i;
		}
		if(c1!=0 && c1!=x){
			ans = max(ans, i - x1);
		}else if(c2!=0){
			ans = max(ans, i-x2);
		}
	}
	cout<<ans;
	return 0;
}