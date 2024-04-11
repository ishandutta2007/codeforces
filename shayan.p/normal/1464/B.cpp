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

ll pref[maxn], suf[maxn];
int cntpr[maxn][2], cntsf[maxn][2];

ll solve(string s, int x, int y){
    int n = sz(s);
    for(int i = 1; i <= n; i++){
	cntpr[i][0] = cntpr[i-1][0] + (s[i-1] != '1');
	cntpr[i][1] = cntpr[i-1][1] + (s[i-1] == '1');
	pref[i] = pref[i-1];
	if(s[i-1] == '1')
	    pref[i]+= 1ll * x * cntpr[i-1][0];
	else
	    pref[i]+= 1ll * y * cntpr[i-1][1];
    }
    cntsf[n+1][0] = cntsf[n+1][1] = suf[n+1] = 0;    
    for(int i = n; i >= 0; i--){
	cntsf[i][0] = cntsf[i+1][0] + (s[i-1] == '0');
	cntsf[i][1] = cntsf[i+1][1] + (s[i-1] != '0');
	suf[i] = suf[i+1];
	if(s[i-1] == '0')
	    suf[i]+= 1ll * x * cntsf[i+1][1];
	else
	    suf[i]+= 1ll * y * cntsf[i+1][0];
    }
    ll ans = min(pref[n], suf[1]);
    for(int i = 1; i < n; i++){
	ans = min(ans, pref[i] + suf[i+1] + 1ll * cntpr[i][0] * cntsf[i+1][1] * x + 1ll * cntpr[i][1] * cntsf[i+1][0] * y);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    ll ans = solve(s, x, y);
    swap(x, y);
    reverse(s.begin(), s.end());
    ans = min(ans, solve(s, x, y));
    return cout << ans << endl, 0;
}