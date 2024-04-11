#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << (x1 == x2 || y1 == y2 ? 1 : 2) << ' ';

    if((x1 + y1) % 2 != (x2 + y2) % 2)
        cout << "0 ";
    else if(abs(x1 - x2) == abs(y1 - y2))
        cout << "1 ";
    else
        cout << "2 ";

    cout << max(abs(x1 - x2), abs(y2 - y1));

}