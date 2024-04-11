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
const int MAX_N = 1;

string str;
int T;

int main(){
	scanf("%d", &T);
	while(T--){
		cin>>str;
		int ans = 0;
		int t = 0;
		bool tf = false;
		for(int i=0; i<str.size(); i++){
			if(str[i]=='1'){
				tf = true;
				t = 0;
			}
			else if(tf && str[i]=='0'){
				ans++;
				t++;
			}
		}
		printf("%d\n", ans-t);
	}
	return 0;
}