// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-21

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2010, mod = 1e9 + 7, inf = 1e9 + 10;

bitset<maxn> dp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	int mx = 0, cnt = 0;
	vector<int> v;
	for(int i = 0; i < 2 * n; i++){
	    int x;
	    cin >> x;
	    if(mx < x){
		if(cnt != 0)
		    v.PB(cnt);
		cnt = 0;
		mx = x;
	    }
	    cnt++;				
	}
	v.PB(cnt);
	
	dp = 0;
	dp[0] = 1;
	for(int x : v){
	    dp = dp | (dp << x);
	}
	if(dp[n])
	    cout << "YES\n";
	else
	    cout << "NO\n";
    }
    return 0;
}