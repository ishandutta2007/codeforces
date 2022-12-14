#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000;

int T, N, M;
vector<int> v1, v2;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		M = N - (N/4);
		v1.clear(); v2.clear();
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			v1.pb(x);
		}
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			v2.pb(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int i1 = N-1, i2 = N-1;
		int s1 = 0, s2 = 0, ans = 0, cnt = 0;
		while(M--){
			s1+=v1[i1--];
			s2+=v2[i2--];
		}
		M = N-(N/4);
		while(s1<s2){
			ans++;
			//cout<<s1<<" "<<s2<<endl;
			cnt++;
			if(i1+1<N){
				s1+=100;
				cnt--;
				s1-=v1[++i1];
			}
			N++;
			if((N-(N/4))==M){
				continue;
			}
			M = N - (N/4);
			
			if(cnt>0){
				s1+=100;
				cnt--;
			}else if(i1>=0){
				s1+=v1[i1--];
			}
			if(i2>=0){
				s2+=v2[i2--];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}