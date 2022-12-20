#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	vector<pii> ans;
	while(n > 2){
	    int sq = sqrt(n);
	    if(sq * sq < n)
		sq++;
	    for(int i = sq+1; i < n; i++)
		ans.PB({i, n});
	    ans.PB({n, sq});
	    ans.PB({n, sq});
	    n = sq;
	}
	cout << sz(ans) << "\n";
	for(pii p : ans)
	    cout << p.F << " " << p.S << "\n";
    }
    return 0;
}