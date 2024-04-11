#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
const double PI = 3.14159265358979323846;

void solve() {
    int n, R, r;
    cin >> n >> R >> r;
    if(R < r){
        cout << "NO";
        return;
    }
    if(R < r * 2){
        if(n == 1){
            cout << "YES";
        } else
            cout << "NO";
        return;
    }
    if(R == r * 2){
        if(n < 3){
            cout << "YES";
        } else
            cout << "NO";
        return;
    }
    double a = asin(r / double(R - r))*2;
    if( 2 * PI - a *n >= -1e-7){
        cout << "YES";
    } else
        cout << "NO";
}