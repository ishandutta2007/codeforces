#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e4 + 13;
//const int M = 1e5 + 13;
const int A = 26;


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    char a, b;
    cin >> a >> b;

    int x = a - 'a';
    int y = b - '1';

    if((x == 0 || x == 7) && (y == 0 || y == 7))
        cout << 3;
    else if(x == 0 || x == 7 || y == 0 || y == 7)
        cout << 5;
    else
        cout << 8 << endl;
}