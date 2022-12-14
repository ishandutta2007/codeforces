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

int N;
string str1, str2;
bool chk[MAX_N+1];


int main(){
	cin>>N;
	while(N--){
		bool tf = false;
		cin>>str1>>str2;
		for(int i=0; i<='z'-'a'; i++){
			chk[i] = false;
		}
		for(int i=0; i<str1.size(); i++)	chk[str1[i]-'a'] = true;
		for(int i=0; i<str2.size(); i++){
			if(chk[str2[i]-'a']){
				tf = true;
				printf("YES\n");
				break;
			}
		}
		if(!tf){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}