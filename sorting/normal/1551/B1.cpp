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
        string s;
        cin >> s;

        int ans = 0, rem = 0;
        map<char, int> cnt;
        for(char c: s)
            ++cnt[c];

        for(char c = 'a'; c <= 'z'; ++c){
            if(cnt[c] >= 2){
                ans += 1;
                continue;
            }
            if(cnt[c] == 1){
                ++rem;
                continue;
            }
        }
        ans += rem / 2;
        cout << ans << "\n";
    }
}