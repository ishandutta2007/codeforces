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
const int MAX_N = 1000000;

int T;
string str;
ll len, t;
int X, now;
int v[MAX_N+1];
bool chk = false;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &X);
		chk = false;
		cin>>str;
		for(int i=0; i<str.size(); i++){
			v[i] = str[i]-'0';
		}
		len = str.size();
		for(int i=1; i<=X; i++){
			now = v[i-1]-1;
			t = len;
			for(int k=0; k<now; k++){
				if(len>=X || chk){
					chk = true;
					len = (len + (t - (ll)i + MOD) % MOD) % MOD;
					continue;
				}
				for(int j=i; j<t; j++){
					if(len>=X || chk){
						chk = true;
						len = (len + (t - (ll)j + MOD) % MOD) % MOD;
						break;
					}
					if(j>=len)	break;
					v[len] = v[j];
					len = (len + 1) % MOD;
				}
			}
			//cout<<now<<" "<<t<<" "<<len<<endl;
		}
		printf("%lld\n", len);
	}
	return 0;
}