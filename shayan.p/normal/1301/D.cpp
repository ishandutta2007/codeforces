// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, k;
    cin >> n >> m >> k;
    if(4 * n * m - 2 * n - 2 * m < k)
	return cout << "NO\n", 0;
    cout << "YES\n";

    vector<pair<int, string> > ans, ans2;
    ans.PB({m-1, "R"});
    ans.PB({m-1, "L"});
    for(int i = 0; i < n-1; i++){
	ans.PB({1, "D"});
	ans.PB({m-1, "RUD"});
	ans.PB({m-1, "L"});
    }
    ans.PB({n-1, "U"});
    int pt = 0;
    while(k >= 0){
	k-= 1ll * sz(ans[pt].S) * ans[pt].F;
	if(k <= 0)
	    break;
	pt++;
    }
    assert(k <= 0);
    while(sz(ans) > pt+1)
	ans.pop_back();
    
    k*=-1;
    ans[sz(ans)-1].F-= k/sz(ans.back().S);
    k%= sz(ans.back().S);
    if(k > 0){
	ans[sz(ans)-1].F--;
	string s = ans.back().S;
	if(ans[sz(ans)-1].F == 0)
	    ans.pop_back();
	while(k--)
	    s.pop_back();
	ans.PB({1, s});
    }

    for(auto x : ans){
	if(x.F != 0)
	    ans2.PB(x);
    }
    
    cout << sz(ans2) << "\n";
    for(auto x : ans2){
	cout << x.F << " " << x.S << "\n";
    }
    return 0;
}