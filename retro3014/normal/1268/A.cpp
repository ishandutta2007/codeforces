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


int N, K;
string str;
string str2;
int main(){
	scanf("%d%d", &N, &K);
	cin>>str;
	str2 = str;
	for(int j=0; j<N; j++){
		if(j>=K){
			str2[j]=str2[j-K];
		}
	}
	bool b = (str2>=str);
	for(int j=min(N-1, K-1); j>=0; j--){
		if(b==false){
			if(str2[j]=='9')	{
				for(int k=j; k<N; k+=K){
					str2[k] = '0';
				}
				continue;
			}
			for(int k=j; k<N; k+=K){
				str2[k]++;
			}
			b = true;
		}
	}
	cout<<N<<endl;
	cout<<str2;
	return 0;
}