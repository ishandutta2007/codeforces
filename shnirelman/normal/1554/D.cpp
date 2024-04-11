//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
3 3
1 1 3
*/

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "a" << '\n';
        return;
    }

    int x = n / 2;
    for(int i = 0; i < x; i++)
        cout << 'a';
    cout << 'b';
    for(int i = 0; i < x - 1; i++)
        cout << 'a';
    if(n % 2 == 1)
        cout << 'c';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();



//    for(int i = 0; i <= m; i++)
//        cout << (n ^ i) << ' ';
//    cout << endl;
}