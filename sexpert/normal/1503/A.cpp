#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// '((' = '))' number of 1s even

bool bal(string &s) {
    int mn = 0, cur = 0;
    for(auto &c : s) {
        if(c == '(')
            cur++;
        else
            cur--;
        mn = min(cur, mn);
    }
    if(mn < 0 || cur != 0)
        return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t1, t2;
    for(int i = 0; i < n; i++)
        t1 += '.';
    t2 = t1;
    vector<int> p1;
    for(int i = 0; i < n; i++)
        if(s[i] == '1')
            p1.push_back(i);

    if(p1.size() % 2) {
        cout << "NO\n";
        return;
    }
    int x = p1.size() / 2;
    for(int i = 0; i < 2 * x; i++) {
        if(i < x)
            t1[p1[i]] = t2[p1[i]] = '(';
        else
            t1[p1[i]] = t2[p1[i]] = ')';
    }
    int c = 0;
    for(int i = 0; i < n; i++) {
        if(t1[i] != '.')
            continue;
        if(c % 2) {
            t1[i] = '(';
            t2[i] = ')';
        }
        else {
            t1[i] = ')';
            t2[i] = '(';
        }
        c++;
    }
    if(!bal(t1) || !bal(t2)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << t1 << '\n' << t2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}