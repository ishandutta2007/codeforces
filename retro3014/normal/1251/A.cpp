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
const int MAX_N = 30;

int T;
string str;

bool chk[MAX_N+1];

int main(){
	cin>>T;
	while(T--){
		cin>>str;
		for(int i=0; i<='z'-'a'; i++){
			chk[i] = false;
		}
		for(int i=0; i<str.size(); i++){
			if(i==str.size()-1){
				chk[str[i]-'a'] = true;
			}else{
				if(str[i]==str[i+1]){
					i++;
				}else{
					chk[str[i]-'a'] = true;
				}
			}
		}
		for(int i=0; i<='z'-'a'; i++){
			if(chk[i]){
				printf("%c", i+'a');
			}
		}
		printf("\n");
	}
	return 0;
}