#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, K = 26;
typedef long long ll;

int n;
ll cnt[2][26];

int ch(char c) {return c - 'a';}

bool same(string &str) {
    for(int i = 0; i < str.length(); i++) if(str[i] != str[0]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int la = 0, nw = 1;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        swap(la, nw);
        fill(cnt[nw], cnt[nw] + 26, 0);

        if(same(str)) {
            int c = ch(str[0]);
            cnt[nw][c] = cnt[la][c] + 1LL * (cnt[la][c] + 1) * str.length();
        }
        else {
            int fc = ch(str[0]), fn = 0;
            for(int j = 0; j < str.length(); j++) {
                if(fc == ch(str[j])) fn++;
                else break;
            }
            int ec = ch(str.back()), en = 0;
            for(int j = str.length() - 1; j >= 0; j--) {
                if(ec == ch(str[j])) en++;
                else break;
            }
            if(fc == ec) {
                if(cnt[la][fc] > 0) cnt[nw][fc] = 1LL + fn + en;
                else cnt[nw][fc] = max(fn, en);
            }
            else {
                cnt[nw][fc] = (cnt[la][fc] > 0) + fn;
                cnt[nw][ec] = (cnt[la][ec] > 0) + en;
            }
            ll cntx = 0;
            for(int j = 0; j < str.length(); j++) {
                cntx++;
                if(j + 1 == str.length() || str[j] != str[j+1]) {
                    int lac = ch(str[j]);
                    cnt[nw][lac] = max(cnt[nw][lac], cntx);
                    cntx = 0;
                }
            }
        }
        for(int j = 0; j < 26; j++) if(cnt[la][j] > 0) cnt[nw][j] = max(cnt[nw][j], 1LL);
    }
    ll res = 0;
    for(int i = 0; i < 26; i++) res = max(res, cnt[nw][i]);
    cout << res << endl;

}