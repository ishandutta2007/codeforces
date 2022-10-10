#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ll dx = bx - ax, dy = by - ay, ex = bx - cx, ey = by - cy;
    if(dx * ey == ex * dy || (dx * dx + dy * dy) != (ex * ex + ey * ey))
        cout << "No\n";
    else
        cout << "Yes\n";
}