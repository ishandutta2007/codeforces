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

int dp[maxn];

int solve(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < sz(s); i++){
	if(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2]))
	    ans++, s[i] = ' ';
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
}