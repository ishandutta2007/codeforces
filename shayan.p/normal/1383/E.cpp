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

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[maxn], SM[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s;
    cin >> s;
    int cnt = 0, cnt2 = 0;
    for(int i = 0; i < sz(s); i++){
	if(s[i] == '1')
	    break;
	cnt++;
    }
    if(cnt == sz(s))
	return cout << cnt << endl, 0;
    s = s.substr(cnt);
    reverse(s.begin(), s.end());
    for(int i = 0; i < sz(s); i++){
	if(s[i] == '1')
	    break;
	cnt2++;
    }
    s = s.substr(cnt2);
    reverse(s.begin(), s.end());
    s.pop_back();
    if(s.empty())
	return cout << 1ll * (cnt + 1) * (cnt2 + 1) % mod, 0;
    int lst = 0;
    dp[0] = 1;
    SM[1] = 1;
    for(int i = 1; i < sz(s); i++){
	if(s[i] == '1')
	    lst = 0;
	else
	    lst++;
	SM[i + 1] = (SM[i] - dp[lst] + SM[i-lst] + 1) % mod;
	SM[i + 1] = (SM[i + 1] + mod) % mod;
	dp[lst] = SM[i - lst] + 1;
    }
    return cout << 1ll * (SM[sz(s)] + 1) * (cnt + 1) % mod * (cnt2 + 1) % mod << endl, 0;
}