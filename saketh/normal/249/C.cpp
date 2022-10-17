#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100100;
const int MAXU = 105;

int N, Q;
double unt[MAXN][MAXU];
int totp[MAXN];

double ans = 0;

double fact[1000000];
double ncr_comp(int n, int r){
    if(r < 0 || r > n) return 0;
    return exp(fact[n] - fact[r] - fact[n-r]);
}
double ncr[500500][10];

double chance(int fresh, int tasted, int picking, int loss){
    if(picking < loss) return 0;
    return ncr[fresh][loss] * ncr[tasted][picking - loss] / ncr[fresh + tasted][picking];
}

int main(){
    fact[0] = 0;
    for(int i=1; i<1000000; i++)
        fact[i] = log(i) + fact[i-1];
    for(int i=0; i<500500; i++)
       for(int j=0; j<10; j++)
          ncr[i][j] = ncr_comp(i, j); 

    setup();
    cin >> N;
    for(int i=0; i<N; i++){
        int ai;
        cin >> ai;
        totp[i] = ai;
        unt[i][ai] = 1;
        if(!ai) ans += 1;
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        int ui, vi, ki;
        cin >> ui >> vi >> ki;
        ui--, vi--;

        ans -= unt[ui][0];

        for(int u=0; u<=min(100, totp[ui]); u++){
            double ov = unt[ui][u];
            unt[ui][u] = 0;
            for(int l=0; l<=min(ki, u); l++){
                double pr = chance(u, totp[ui] - u, ki, l);
                unt[ui][u-l] += pr * ov;
            }
        }

        ans += unt[ui][0];
        printf("%0.9f\n", ans);
        totp[ui] -= ki;
        totp[vi] += ki;
    }
}