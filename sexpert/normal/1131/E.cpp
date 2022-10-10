#include <bits/stdc++.h>
using namespace std;

long long cnt[26], ncnt[26], mx[26];
const long long INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++) {
        string s = v[i];
        memset(ncnt, 0, sizeof ncnt);
        memset(mx, 0, sizeof mx);
        for(int j = 0; j < s.length(); j++)
            ncnt[s[j] - 'a']++;
        for(int c = 0; c < 26; c++) {
            long long sf = 0;
            for(int j = 0; j < s.length(); j++) {
                if(s[j] - 'a' == c)
                    sf++;
                else {
                    mx[c] = max(mx[c], sf);
                    sf = 0;
                }
            }
            mx[c] = max(mx[c], sf);
            if(cnt[c] == 0) {
                cnt[c] = mx[c];
                continue;
            }
            if(ncnt[c] == s.length()) {
                cnt[c] = (cnt[c] + 1ll)*(ncnt[c] + 1ll) - 1ll;
                if(cnt[c] > INF)
                    cnt[c] = INF;
                continue;
            }
            long long ext = 0;
            for(int j = 0; j < s.length(); j++) {
                if(s[j] - 'a' != c)
                    break;
                ext++;
            }
            for(int j = s.length() - 1; j >= 0; j--) {
                if(s[j] - 'a' != c)
                    break;
                ext++;
            }
            cnt[c] = max(mx[c], 1ll + ext);
        }
    }
    cout << endl;
    cout << *max_element(cnt, cnt + 26) << endl;
}