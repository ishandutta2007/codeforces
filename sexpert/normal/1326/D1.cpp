#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi manacher(string s) {
    int n = s.size(), L = -1, R = -1;
    vi res(n);
    for(int i = 0; i < n; i++) {
        if(i <= R)
            res[i] = min(R - i, res[L + R - i]);
        while(i + res[i] + 1 < n && i - res[i] - 1 >= 0 && s[i - res[i] - 1] == s[i + res[i] + 1])
            res[i]++;
        if(i + res[i] >= R) {
            L = i - res[i];
            R = i + res[i];
        }
    }
    return res;
}

string best(string s) {
    string ma = "*";
    for(auto c : s) {
        ma += c;
        ma += '*';
    }
    vi res = manacher(ma);
    int n = s.size(), r = n, bst = 0;
    for(int l = 0; l < n; l++) {
        if(r == n - l) {
            if(s[r - 1] == s[l])
                r--;
        }
        if(r <= l + 1)
            break;
        int st = n - r;
        if(st > l || res[st + l + 1] >= l - st)
            bst = l;
    }
    string fin = s.substr(0, bst + 1);
    r = max(r, n - bst);
    if(r < n)
        fin += s.substr(r);
    return fin;
}

void solve() {
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    if(s == t) {
        cout << s << '\n';
        return;
    }
    string uwu = best(s), owo = best(t);
    if(uwu.length() >= owo.length())
        cout << uwu << '\n';
    else
        cout << owo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}