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

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], ans[maxn];

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> mp;
    map<int, int> ok;
    set<pii> st;
    for(int i = 0; i < n; i++)
	cin >> a[i], mp[a[i]]++;
    for(auto x : mp)
	st.insert({x.S, x.F});
    int bad = -1;
    for(int i = 1; i <= n+1; i++){
	if(mp.count(i) == 0)
	    bad = i;
    }
    auto big = [&](){ return st.rbegin()->S; };
    auto del = [&](int x){
		   st.erase({mp[x], x});
		   if(--mp[x] == 0){
		       mp.erase(x);
		   }
		   else{
		       st.insert({mp[x], x});
		   }
	       };
    for(int i = 0; i < x; i++){
	int c = big();
	ok[c]++;
	del(c);
    }

    vector<pii> vec;
    set<int> poses;
    
    for(int i = 0; i < n; i++){
	if(ok[ a[i] ] != 0){
	    --ok[ a[i] ];
	    poses.insert(i);
	    ans[i] = a[i];
	}
	else{
	    vec.PB({a[i], i});
	}
    }
    sort(vec.begin(), vec.end());
    int N = sz(vec);    
    for(int i = 0; i < N; i++)
	ans[ vec[i].S ] = vec[(i + (N/2)) % N].F;
    int t = n-y;
    for(int i = 0; i < n; i++){
	if(poses.count(i) == 0 && a[i] == ans[i])
	    ans[i] = bad, t--;
    }
    if(t < 0){
	cout << "NO\n";
	return;
    }
    for(int i = 0; i < n; i++){
	if(poses.count(i) == 0 && t != 0 && ans[i] != bad)
	    t--, ans[i] = bad;
    }
	
    cout << "YES\n";
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    cout << "\n";	
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
    return 0;
}