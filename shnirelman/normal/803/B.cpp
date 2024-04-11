//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lst = -INF;
    vector<int> res(n, INF);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0)
            lst = i;
        res[i] = i - lst;
    }

    lst = INF;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == 0)
            lst = i;
        res[i] = min(res[i], lst - i);
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }

}