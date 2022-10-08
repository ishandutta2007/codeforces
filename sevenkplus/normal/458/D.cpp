#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n,m,k;
ld lw[N];

ld logC(int n, int k) {
    return lw[n]-lw[k]-lw[n-k];
}

const ld MAX = 1.0e99;

int main()
{
    lw[0] = 0;
    for (int i = 1; i < N; i ++) lw[i] = lw[i-1]+log10(i);
    cin >> n >> m >> k;
    ld S = 0;
    for (int i = 0; i <= n; i ++) 
        for (int j = 0; j <= n; j ++) {
            int s = (i+j)*n-i*j;
            if (s > k) continue;
            ld lf = logC(n,i)+logC(n,j)+logC(m-s,k-s)-logC(m,k);
            if (lf > 99) {
                puts("1e99");
                return 0;
            }
            S += pow((ld)10,(ld)lf);
        }
    if (S > MAX) {
        puts("1e99");
        return 0;
    }
    cout << setprecision(18) << S << endl;
    return 0;
}