#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N; cin >> N;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if ((bx - ax) * (cx - ax) > 0 && (by - ay) * (cy - ay) > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}