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
int N;
int w, b;
vector<int> v;
char c;

int main(){
	cin>>N>>str;
	for(int i=0; i<N; i++){
		if(str[i]=='W'){
			w++;
		}else{
			b++;
		}
	}
	if(N%2){
		if(w%2){
			c='B';
		}else{
			c='W';
		}
	}else{
		if(w%2){
			printf("-1");
			return 0;
		}
		c='B';
	}	
	for(int i=0; i<N-1; i++){
		if(str[i]==c){
			v.pb(i+1);
			if(str[i+1]=='W'){
				str[i+1] = 'B';
			}else{
				str[i+1] = 'W';
			}
		}
	}
	cout<<v.size()<<endl;
	for(int i=0; i<v.size(); i++){
		printf("%d ", v[i]);
	}
	return 0;
}