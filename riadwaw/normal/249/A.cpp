#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <list>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    clock_t start = clock();
#else
#endif
    //ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

void solve(){
        int y1 ;
        int y2 ;
        int yw ;
        int xb ;
        int yb ;
        int  r ;
        cin >> y1 >> y2 >> yw >> xb >> yb >> r;
        
        yw -= r;
        double want =  y1 + r;//(y1 + y2) / 2.0;
        want = yw + (yw - want);
        double fly = want - yb; 

        double x = ((want -yw ) / 1.0 /fly * xb);
        
        //(0, want), (xb, yb)
        
        int b = 1;
        double c = -want;
        double a = (want - yb) / 1.0 /xb;
        double to = yw + (yw - y2);
        
        
        double rast = abs((b * to + c) / sqrt(a * a + b * b));

        if(rast <= r){
            cout << -1;
            return;
        }
        printf("%.20lf", x);
}