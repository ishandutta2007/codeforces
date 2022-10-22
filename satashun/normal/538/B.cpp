#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int n;
vector<int> vec;
int dp[1000010];
int pr[1000010];

int main(){
    cin >> n;
    vec.pb(1);
    rep(i, 6){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	vector<int> nv = vec;
	for(int x : vec){
	    nv.pb(x * 10);
	    nv.pb(x * 10 + 1);
	}
	swap(nv, vec);
    }
    set<int> ss;
    dp[0] = 0;
    for(int x : vec){
	if(x <= 1000000){
	    ss.insert(x);
	}
    }
    vec.clear();
    for(const int x : ss) vec.pb(x);

    for(int i = 1; i <= 1000000; ++i){
	dp[i] = 1145141;
	for(int x : vec) if(x <= i){
	    if(dp[i] > dp[i - x] + 1){
		pr[i] = x;
		dp[i] = dp[i - x] + 1;
	    }
	}
    }

    vector<int> ans;
    while(n){
	ans.pb(pr[n]);
	n -= pr[n];
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    return 0;
}