#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt[2]{0, 0};
        for(int i = 0; i < s.size(); ++i)
            cnt[s[i] - '0']++;

        ll ans = (ll)cnt[0] * (ll)cnt[1];

        int cnt2 = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != s[i - 1]){
                check_max(ans, (ll)cnt2 * cnt2);
                cnt2 = 1;
            }
            else ++cnt2;
        }
        check_max(ans, (ll)cnt2 * cnt2);
        cout << ans << "\n";
    }
}