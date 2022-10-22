#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll INF = 1e9 + 7;
const ll Q = 257;

bool isNumber(string s) {
    assert(s.size());
    for (char c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

bool isWord(string s) {
    assert(s.size());
    if (s[0] >= '0' && s[0] <= '9') {
        return false;
    }
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            continue;
        }
        if (c >= 'A' && c <= 'Z') {
            continue;
        }
        if (c == '_' || c == '$') {
            continue;
        }
        if (c >= '0' && c <= '9') {
            continue;
        }
        return false;
    }
    return true;
}

set <string> rest;

bool isReserve(string s) {
    return rest.find(s) != rest.end();
}

bool isGood(string s) {
    return isNumber(s) || isWord(s) || isReserve(s);
}

vector <string> parse(string s) {
    int n = s.size();
    vector <string> res;
    int it = 0;
    while (it < n) {
        if (s[it] == '#') break;
        if (s[it] == ' ') {
            it++;
            continue;
        }
        string now = "";
        int last = -1;
        for (int i = it; i < n; i++) {
            now += s[i];
            if (isGood(now)) {
                last = i;
            }
        }
        assert(last != -1);
        res.push_back(s.substr(it, last - it + 1));
        it = last + 1;
    }
    return res;
}

string add(string s) {
    int cnt = 0;
    while (s.size() && s.back() == 'z') {
        cnt++;
        s.pop_back();
    }
    if (s.size()) {
        s.back()++;
    } else {
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        s += 'a';
    }
    return s;
}

ll gh(string s) {
    ll h = 0;
    for (char c : s) {
        h = (h * Q + c) % INF;
    }
    return h;
}

bool check(vector <string> a) {
    string s = "";
    for (auto t : a) {
        s += t;
    }
    return a == parse(s);
}

vector <vector <bool> > bad;
set <ll> hashs;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        rest.insert(s);
        hashs.insert(gh(s));
    }
    int m;
    cin >> m;
    string s;
    getline(cin, s);
    vector <string> all;
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        auto now = parse(s);
        for (auto t : now) {
            all.push_back(t);
        }
    }
//    for (auto t : all) {
//        cout << t << " ";
//    }
//    cout << "\n";
    n = all.size();
    string r = "a";
    while (isReserve(r)) {
        r = add(r);
    }
    vector <bool> ch(n, false);
    for (int i = 0; i < n; i++) {
        if (ch[i] || isReserve(all[i]) || isNumber(all[i])) continue;
        string t = all[i];
        for (int j = i; j < n; j++) {
            if (!ch[j] && all[j] == t) {
                ch[j] = true;
                all[j] = r;
            }
        }
        do {
            r = add(r);
        } while (isReserve(r));
    }
    //cout << all.size() << "\n";
//    for (auto t : all) {
//        cout << t << " ";
//    }
//    cout << "\n";
    bad.resize(n + 1, vector <bool> (n + 1, true));
    for (int i = 0; i < n; i++) {
        string s = all[i];
        ll h = gh(s);
        bad[i][i] = false;
        for (int j = i + 1; j < n; j++) {
            string t = all[j];
            assert(t.size());
            if (j == i + 1 && (isWord(s + t[0]) || isNumber(s + t[0]))) {
                break;
            }
            bool can = true;
            for (char c : t) {
                h = (h * Q + c) % INF;
                if (hashs.find(h) != hashs.end()) {
                    can = false;
                    break;
                }
            }
            if (!can) {
                break;
            }
            //cout << i << " " << j << "\n";
            bad[i][j] = false;
            s += t;
        }
    }
    for (int len = 0; len <= n; len++) {
        for (int i = 1; i < n; i++) {
            if (i + len >= n) break;
            if (bad[i][i + len]) {
                bad[i - 1][i + len] = true;
                if (i + len + 1 < n) {
                    bad[i][i + len + 1] = true;
                }
            }
        }
    }
    vector <int> dp(n + 1, INF);
    vector <int> pred(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (bad[i][j - 1]) {
                break;
            }
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                pred[j] = i;
            }
        }
    }
    vector <bool> space(n, false);
    int now = n;
    while (now != 0) {
        space[now - 1] = true;
        now = pred[now];
    }
    space[n - 1] = false;
    for (int i = 0; i < n; i++) {
        cout << all[i];
        if (space[i]) {
            cout << " ";
        }
    }
}
/*
10
( ) + ++ : -> >> >>: b c)
2
($val1++ + +4 kb) >> :out
b-> + 10 >>: t # using >>:

16
fun while return var { } ( ) , ; > = + ++ - --
9
fun fib(num) { #compute fibs
    var return_value = 1, prev = 0, temp;
    while (num > 0) {
        temp = return_value; return_value = return_value + prev;
        prev = temp;
        num--;
    }
    return return_value;
}
*/