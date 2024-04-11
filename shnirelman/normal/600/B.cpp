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
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < m; j++)
        cin >> b[j];

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++) {
        cout << int(upper_bound(a.begin(), a.end(), b[i]) - a.begin()) << ' ';
    }

}