//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%d",&a)
#define Put(a) printf("%d\n",a);
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e5 + 1e3;
ll val[26];
ll sum[Maxn];
vector<int> Occ[26];
map<ll,int> small;
map<ll,int> big;
string S;
int main(){
	ios_base::sync_with_stdio(0);
	For(i,0,26)
		cin >> val[i];
	cin >> S;
	int n = S.size();
	sum[0] = val[S[0] - 'a'];
	For(i,1,n){
		sum[i] = sum[i-1] + val[S[i]-'a'];
	}
	ll ans = 0;
	For(i,0,26){
		For(j,0,n){
			if(S[j] - 'a' == i){
				if(j)
					ans += small[sum[j-1]];
				small[sum[j]]++;
				if(j)
					big[sum[j-1]]++;
			}
		}
		big.clear();
		small.clear();
	}
	cout << ans << endl;
	return 0;
}