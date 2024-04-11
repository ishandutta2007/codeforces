#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

struct letter {
    int cnt[26];
    letter() { fill(cnt, cnt + 26, 0); }
    bool operator== (const letter &o) const {
        for(int i = 0; i < 26; i++)
            if(cnt[i] != o.cnt[i]) return false;
        return true;
    }
    letter operator- (const letter &o) {
        letter res;
        for(int i = 0; i < 26; i++)
            res.cnt[i] = cnt[i] - o.cnt[i];
        return res;
    }
    bool palin() {
        int odds = 0;
        for(int i = 0; i < 26; i++)
            odds += (cnt[i] % 2);
        return (odds <= 1);
    }
};

template <class T>
vi manacher(vector<T> &s) {
    int n = s.size(), L = -1, R = -1;
    vi p(n);
    for(int i = 0; i < n; i++) {
        if(i <= R) p[i] = min(p[R + L - i], R - i);
        while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 && s[i + p[i] + 1] == s[i - p[i] - 1]) p[i]++;
        if(i + p[i] > R) { R = i + p[i]; L = i - p[i]; }
    }
    return p;
}

const int MAXN = 255;
letter pref[MAXN][MAXN];
char board[MAXN][MAXN];
vector<letter> str;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    for(int r = 1; r <= n; r++) {
        pref[r][0] = letter();
        for(int c = 1; c <= m; c++) {
            pref[r][c] = pref[r][c - 1];
            pref[r][c].cnt[board[r][c] - 'a']++;
        }
    }
    ll ans = 0;
    for(int l = 1; l <= m; l++) {
        for(int r = l; r <= m; r++) {
            str.clear();
            str.push_back(letter());
            int bad = 0;
            for(int i = 1; i <= n; i++) {
                str.push_back(pref[i][r] - pref[i][l - 1]);
                if(!str.back().palin()) {
                    str.pop_back();
                    auto p = manacher(str);
                    ll tot = 0;
                    for(auto x : p)
                        ans += ((ll)x + 1ll)/2ll;
                    str.clear();
                }
                str.push_back(letter());
            }
            auto p = manacher(str);
            for(auto x : p)
                ans += ((ll)x + 1ll)/2ll;
            //cout << l << " " << r << " " << tot << endl; *a*b*a*b*b*a*
        }
    }
    cout << ans << endl;
}