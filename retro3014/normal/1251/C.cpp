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

int T;
vector<int> v1, v2;
string str;

int main(){
	cin>>T;
	while(T--){
		cin>>str;
		while(!v1.empty())	v1.pop_back();
		while(!v2.empty())	v2.pop_back();
		for(int i=0; i<str.size(); i++){
			int n = (int)(str[i]-'0');
			if(n%2){
				v1.pb(n);
			}else{
				v2.pb(n);
			}
		}
		int idx1 = 0, idx2 = 0;
		while(idx1<v1.size() || idx2<v2.size()){
			if(idx1==v1.size()){
				printf("%d", v2[idx2]);
				idx2++;
			}else if(idx2==v2.size()){
				printf("%d", v1[idx1]);
				idx1++;
			}else{
				if(v1[idx1]>v2[idx2]){
					printf("%d", v2[idx2]);
					idx2++;
				}else{
					printf("%d", v1[idx1]);
					idx1++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}