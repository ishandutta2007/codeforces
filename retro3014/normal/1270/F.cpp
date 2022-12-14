#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
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
const int MAX_N = 200000;
const int MAX_K = 2000;

int N;
string str;
ll D[MAX_N+1];
int nxt[MAX_N+1];
ll ans = 0;
vector<pii> query;

ll calc(int x, int y, int z){
	//TEST cout<<x<<" "<<y<<" "<<z<<" ";
	ll t = D[z] - D[y] + 1LL, n1 = (ll)z - (ll)y + 1LL, n2 = (ll)z - (ll)x + 1LL;
	n1 = (n1 + t - 1) / t; n2 = n2 / t;
	//TEST cout<<n2-n1+1LL<<endl;
	return (n2-n1+1LL);
}

ll n1, n2, n;

int mp[MAX_N+1];

vector<pll> vt;
int num[MAX_N+1];

int main(){
	cin>>str; 
	//for(int i=0 ;i<10000; i++)	str.pb('1');
	N = str.size();
	str.pb('0');
	for(int i=str.size()-1; i>0; i--){
		str[i]=str[i-1];
	}
	str[0] = '0';
	int lft = 0;
	for(int i=1; i<=N; i++){
		D[i] = D[i-1] + (str[i] - '0');
		nxt[i] = lft;
		if(str[i]=='1')	lft = i;
	}
	for(int i=1; i<=N; i++){
		int now = i, cnt = MAX_K;
		if(str[i]=='0'){
			now = nxt[now];
		}
		while(now>0 && cnt>0){
			cnt--;
			int l = nxt[now]+1;
			n = D[i]-D[now]+1LL, n1 = (ll)i-(ll)now+1LL, n2=(ll)i-(ll)l+1LL;
			n1 = (n1 + n - 1LL) / n; n2/=n;
			ans += (n2-n1+1LL);
			now = nxt[now];
		}
		if(now>0){
			query.pb({now-1, i});
		}
		//cout<<i<<" "<<ans<<endl;
	}
	//cout<<"*"<<endl;
	sort(query.begin(), query.end());
	int idx = 0;
	for(int k=1; k<=(MAX_N/MAX_K); k++){
		idx = 0;
		//printf("%d\n", k);
		//init();
		for(int i=0; i<=N; i++){
			vt.pb({(ll)k*D[i]-(ll)i, (ll)i});
		}
		sort(vt.begin(), vt.end());
		int tmp = 0;
		for(int i=0; i<vt.size(); i++){
			if(i!=0 && vt[i-1].first!=vt[i].first){
				tmp++;
			}
			num[vt[i].second] = tmp;
		}
		while(!vt.empty())	vt.pop_back();
		for(int i=0; i<=N; i++){
			mp[num[i]]++;
			while(idx<query.size() && query[idx].first==i){
				ans += (ll)mp[num[query[idx].second]];
				idx++;
			}
		}
		for(int i=0; i<=N; i++){
			mp[i] = 0;
		}
		//cout<<k<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}