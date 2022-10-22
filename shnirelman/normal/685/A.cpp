#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int n, m;
int ans = 0;

void calc(int cura, int curb, int a, int b, set<int> used) {
    if(b == 0) {
        ans += (cura < n && curb < m);
        return;
    }

    if(a > 0) {
        for(int i = 0; i < 7; i++) if(used.count(i) == 0) {
            used.insert(i);
            calc(cura * 7 + i, curb, a - 1, b, used);
            used.erase(i);
        }
    } else {
        for(int i = 0; i < 7; i++) if(used.count(i) == 0) {
            used.insert(i);
            calc(cura, curb * 7 + i, a, b - 1, used);
            used.erase(i);
        }
    }
}

int main() {

    cin  >> n >> m;

    int a = (n == 1), b = (m == 1);
    for(li i = 1; i < n; i *= 7)
        a++;
    for(li i = 1; i < m; i *= 7)
        b++;

//    cout << a << ' ' << b << endl;

    if(a + b > 7) {
        cout << 0 << endl;
        return 0;
    }

    set<int> st;
    calc(0, 0, a, b, st);

    cout << ans << endl;
}