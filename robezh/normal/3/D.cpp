#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)5e4 + 50;

string str;
char rs[N];
ll sum = 0;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    int pt = 0;
    for(int i = 0; i < n; i++) {
        while(str[pt] != '?' && pt < n) pt++;
        if(pt == n) break;
        int x, y; cin >> x >> y;
        sum += x;
        a[pt] = y - x;
        pt++;
    }

    multiset<P> S;
    int bal = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '?') {
            if(bal >= 1) {
                rs[i] = ')';
                S.insert({a[i], i});
                bal--;
            }
            else {
                rs[i] = '(';
                if(!S.empty() && S.rbegin()->first > a[i]) {
                    rs[S.rbegin() -> second] = '(';
                    rs[i] = ')';
                    S.erase(S.find(*S.rbegin()));
                    S.insert({a[i], i});
                }
                bal++;
            }
        }
        else {
            if(str[i] == '(') {
                bal++;
            }
            else {
                bal--;
                if(bal < 0) {
                    if(S.empty()) return cout << "-1" << endl, 0;
                    rs[S.rbegin() -> second] = '(';
                    S.erase(S.find(*S.rbegin()));
                    bal += 2;
                }
            }
        }
    }
    if(bal != 0) return cout << "-1" << endl, 0;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '?') {
            if(rs[i] == ')') res += a[i];
        }
        else rs[i] = str[i];
    }
    cout << res + sum << "\n";
    for(int i = 0; i < n; i++) cout << rs[i];
    cout << '\n';
}