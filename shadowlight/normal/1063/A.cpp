#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

bool isPr(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int calc(string s) {
    int res = 0;
    int n = s.size();
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (isPr(s.substr(l, r - l  +1))) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> cnt(Q, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    string res = "";
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res += (char) (i + 'a');
        }
    }
    cout << res << "\n";
    //cout << calc(t) << " " << calc(res) << "\n";
}