// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-24

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

set<int> v[20];

void solve(){
    for(int i = 0; i < 20; i++)
	v[i].clear();
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++){
	if(a[i] > b[i]){
	    cout << -1 << "\n";
	    return;
	}
	v[ a[i] - 'a' ].insert( b[i] - 'a' );
    }
    int ans = 0;
    for(int i = 0; i < 20; i++){
	if(v[i].count(i))
	    v[i].erase(i);
	if(!v[i].empty()){
	    int x = *v[i].begin();
	    ans++;
	    for(int j : v[i])
		v[x].insert(j);
	}
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
}