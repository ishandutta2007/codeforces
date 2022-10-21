#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int len;
string s;
int n;
int psum[26][N];
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> len;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= len; i++) {
        for(int c = 0; c < 26; c++) {
            psum[c][i] = psum[c][i-1] + ((s[i] - 'a') == c);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int tlen = t.length();
        t = " " + t;
        memset(cnt, 0, sizeof(cnt));
        for(int j = 1; j <= tlen; j++) cnt[t[j] - 'a']++;
        int l = 0, r = len, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            bool good = true;
            for(int c = 0; c < 26; c++) {
                if(psum[c][mid] < cnt[c]) {
                    good = false;
                    break;
                }
            }
            if(good) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}