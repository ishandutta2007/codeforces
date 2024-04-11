#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

int lb(int j) {
    return j - (j&(j-1));
}

int calc(int x, int dx) {
    int ans = 0;
    
    for (int pot = 16; pot >= 1; pot >>= 1) {
        if (dx & pot) {
            if (x < pot) {
                x = pot+(pot-x-1);
                ans ^= 2*pot-1;
            }
            
            for (int y = pot; y <= x; y++) dx ^= lb(y);
            x = pot-1;
        }
        else {
            if (x >= pot) {
                x -= pot;
                ans ^= pot;
            }
        }
        
        //cerr << "pot " << pot << " x " << x << " dx " << dx << endl;
    }
    
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    
    int tttt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-1; j++) {
            int kk = __builtin_ctz(j);
            cout << (1<<(2*kk+1)) << " ";
            tttt += 1<<(2*kk+1);
        }
        cout << endl;
    }
    
    for (int j = 1; j <= n-1; j++) {
        for (int i = 1; i <= n; i++) {
            int kk = __builtin_ctz(j);
            cout << (1<<(2*kk)) << " ";
            tttt += 1<<(2*kk);
        }
        cout << endl;
    }
    
    //cout << "tttt: " << tttt << endl;
    int cx = 0, cy = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        
        int dx = 0, dy = 0;
        for (int i = 0; i < 10; i++) {
            if (i%2 == 1 && ( x & (1<<i) ) ) dx ^= 1<<(i/2);
            if (i%2 == 0 && ( x & (1<<i) ) ) dy ^= 1<<(i/2);
        }
        
        cx = calc(cx, dx);
        cy = calc(cy, dy);
        
        cout << cy+1 << " " << cx+1 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}