#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10;

ll val[maxn];
int id[maxn];

ll solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
	cin >> id[i];
	--id[i];
    }
    for(int i = 0; i < m; i++){
	cin >> val[i];
    }
    sort(id, id + n);
    int l = 0, r = n + 1;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	int nw = 0;
	bool ok = 1;
	for(int i = n-mid; i < n; i++)
	    ok&= nw <= id[i], nw++;
	if(ok)
	    l = mid;
	else
	    r = mid;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
	ans+= val[id[i]];
    }
    ll bst = 0, num = 0;
    for(int i = 0; i < l; i++){
	num+= val[id[n-1-i]] - val[i];
	bst = max(bst, num);
    }
    return ans - bst;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
}