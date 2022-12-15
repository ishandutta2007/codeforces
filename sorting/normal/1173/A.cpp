#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;
    cin >> x >> y >> z;

    int mx, mn;

    mx = mn = x - y;
    mx += z;
    mn -= z;

    if(mx > 0 && mn > 0)
        cout << "+";
    else if(mx < 0 && mn < 0)
        cout << "-";
    else if(mx == 0 && mn == 0)
        cout << "0";
    else
        cout << "?";
}