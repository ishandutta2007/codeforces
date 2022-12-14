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

int N, M;
string str;

int query(){
	cout<<"? "<<str<<endl;
	cout.flush();
	int r;
	cin>>r;
	return r;
}

vector<pii> vt;

int main(){
	cin>>N>>M;
	for(int i=1; i<=M; i++){
		str.pb('0');
	}
	for(int i=0; i<M; i++){
		str[i]='1';
		vt.push_back({query(), i});
		str[i]='0';
	}
	sort(vt.begin(), vt.end());
	int sum = 0;
	for(int i=0; i<M; i++){
		sum += vt[i].first;
		str[vt[i].second] = '1';
		int ret = query();
		if(ret!=sum){
			str[vt[i].second] = '0';
			sum-=vt[i].first;
		}
	}
	cout<<"! "<<sum<<endl;
	cout.flush();

	return 0;
}