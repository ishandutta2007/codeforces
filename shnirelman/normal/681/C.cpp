#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;



int main() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s[0] == 'i') {
            cin >> a[i].s;
            a[i].f = 1;
        } else if(s[0] == 'g') {
            cin >> a[i].s;
            a[i].f = 0;
        } else {
            a[i].f = a[i].s = -1;
        }
    }

    vector<pii> b;
    multiset<int> ms;
    for(int i = 0; i < n; i++) {
        if(a[i].f == -1) {
            if(ms.size() >= 1)
                ms.erase(ms.begin());
            else
                b.emplace_back(1, 1);
            b.push_back(a[i]);
        } else if(a[i].f == 0) {
            while(!ms.empty() && *ms.begin() < a[i].s) {
                b.emplace_back(-1, -1);
                ms.erase(ms.begin());
            }

            if(ms.empty() || *ms.begin() != a[i].s) {
                b.emplace_back(1, a[i].s);
                ms.insert(a[i].s);
            }
            b.push_back(a[i]);
        } else {
            b.push_back(a[i]);
            ms.insert(a[i].s);
        }
    }

    cout << b.size() << endl;
    for(auto p : b)
        if(p.f == -1)
            cout << "removeMin\n";
        else if(p.f == 0)
            cout << "getMin " << p.s << '\n';
        else
            cout << "insert " << p.s << '\n';
}