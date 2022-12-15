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
        string k;
        cin >> k;

        string s;
        cin >> s;

        map<char, int> pos;
        for(int i = 0; i < k.size(); ++i)
            pos[k[i]] = i;

        int ans = 0;
        for(int i = 0; i < (int)s.size() - 1; ++i)
            ans += abs(pos[s[i]] - pos[s[i + 1]]);
        cout << ans << "\n";
    }
}