#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

void solve(){
    string s;
    cin >> s;

    int ans = 3;
    int cnt[2]{0, 0};
    for(char c: s)
        cnt[c - '0']++;
    if(!cnt[0]) ans = 0;
    else if(!cnt[1]) ans = 1;
    else ans = 2;

    int curr = 0;
    for(int i = 0; i < (int)s.size(); ++i)
        if(s[i] == '0' && (i == (int)s.size() - 1 || s[i + 1] == '1'))
            ++curr;
    check_min(ans, curr);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}