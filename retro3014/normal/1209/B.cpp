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
const int MAX_N = 110;
const int T = 1000;

int N;
string str;
pii p[MAX_N+1];
int ans = 0;

void calc(){
	int cnt = 0;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='1'){
			cnt++;
		}
	}
	ans = max(ans, cnt);
}

int main(){
	cin>>N;
	cin>>str;
	for(int i=0; i<N; i++){
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	calc();
	for(int i=1; i<=T; i++){
		for(int j=0; j<N; j++){
			if(i>=p[j].second && ((i-p[j].second)%p[j].first)==0){
				str[j] = (char)('1' + '0' - str[j]);
			}
		}
		//cout<<str<<endl;
		calc();
	}
	cout<<ans;
	return 0;
}