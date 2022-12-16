// Never let them see you bleed...
// Shayan.P  2020-06-11

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 998244353, inf = 1e9 + 10;

int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
	cin >> a[i];
    for(int j = 0; j < m; j++)
	cin >> b[j];
    vector<int> vec, vecid;
    vector<int> pos;
    vec.PB(a[n-1]);
    vecid.PB(n-1);
    for(int i = n-2; i >= 0; i--){
	if(vec.back() > a[i])
	    vec.PB(a[i]), vecid.PB(i);
    }
    reverse(vec.begin(), vec.end());
    reverse(vecid.begin(), vecid.end());    
    for(int i = 0; i < m; i++){
	int id = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
	if(id == sz(vec) || vec[id] != b[i])
	    return cout << 0 << endl, 0;
	pos.PB(id);
    }
    int ans = pos[0] == 0;
    for(int i = 1; i < m; i++){
	ans = 1ll * ans * (vecid[pos[i]] - vecid[pos[i]-1]) % mod;
    }
    return cout << ans << endl, 0;
}