#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int f(long long x) {
    int r = 0;
    while (x > 0) {
        r += (x % 2);
        x /= 2;
    }
    return r;
}

int main(){
//    freopen(TASK".in","r",stdin);   
//    freopen(TASK".out","w",stdout);
    int n;
    cin >> n;
    while (n--) {
        long long l, r;
        cin >> l >> r;

        int ma = f(r);
        long long ans = r;

        for (int i = 0; i < 62; i++) if (r & pw(i)) {
            long long x = r - (r & (pw(i + 1) - 1)) + pw(i) - 1;
            if (x < l) continue;

            int t = f(x);
            if (t >= ma) {
                ma = t;
                ans = x;
            }
        }
        if (f(l) >= ma) ans = l;

        cout << ans << endl;
        
    }
    return 0;
}