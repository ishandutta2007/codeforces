#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

void add(int &ans, int cnt[]){
    if(!cnt[0]) ans += 0;
    else if(!cnt[1]) ans += 1;
    else ans += 2;
}

void solve(){
    int n;
    string s[2];
    cin >> n >> s[0] >> s[1];

    int ans = 0;
    int cnt[2]{0, 0};
    for(int i = 0; i < n; ++i){
        if(s[0][i] - '0' + s[1][i] - '0' == 1){
            add(ans, cnt);
            cnt[0] = cnt[1] = 0;
            ans += 2;
            continue;
        }
        if(s[0][i] == '0'){
            if(cnt[0]){
                add(ans, cnt);
                cnt[0] = cnt[1] = 0;
            }
            ++cnt[0];
            if(cnt[0] && cnt[1]){
                add(ans, cnt);
                cnt[0] = cnt[1] = 0;
            }
            continue;
        }
        ++cnt[1];
        if(cnt[0] && cnt[1]){
            add(ans, cnt);
            cnt[0] = cnt[1] = 0;
        }
    }
    add(ans, cnt);
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