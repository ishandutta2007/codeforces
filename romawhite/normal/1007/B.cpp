#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const Int INF2 = Int(INF) * 5000;
const Int INF3 = Int(INF) * INF;
const int MAX = 100007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

int p[MAX];
int d[MAX];


int gcd(int a, int b)
{
    if (!b)
    {
        return a;
    }
    return gcd(b , a % b);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt" , "w", stdout);

    for(int i = 2; i < MAX; ++i)
        if (!p[i])
            for(Int j = 1LL * i * i; j < MAX; j += i) {
                if (!p[j])
                    p[j] = i;
            }


    d[1] = 1;

    FOR(i,2,MAX)
    {
        if (p[i] == 0) p[i] = i;
        int x = i;
        int c = 0;
        while (x % p[i] == 0)
        {
            x /= p[i];
            ++ c;
        }
        d[i] = d[x] * (c + 1);
    }

    int t;
    cin >> t;

//    t = 100000;
    FOR(tt,0,t)
    {
        int a , b , c;
        scanf("%d%d%d" , &a , &b , &c);
//        a = 100000;
//        b = 100000;
//        c = 100000;
//        int res2 = 0;
//        FOR(i,1,max(a , max(b , c)) + 1)
//            FOR(j,1,i + 1)
//                FOR(k,1,j + 1)
//                {
//                    bool ok = false;
//                    if (a % i == 0 && b % j == 0 && c % k == 0)
//                        ok = true;
//                    if (a % i == 0 && b % k == 0 && c % j == 0)
//                        ok = true;
//                    if (a % j == 0 && b % i == 0 && c % k == 0)
//                        ok = true;
//                    if (a % j == 0 && b % k == 0 && c % i == 0)
//                        ok = true;
//                    if (a % k == 0 && b % j == 0 && c % i == 0)
//                        ok = true;
//                    if (a % k == 0 && b % i == 0 && c % j == 0)
//                        ok = true;
//                    res2 += ok;
//
//                }
//        cout << res2 << ' ';


        VI D(8);
        D[1] = d[a] - d[gcd(a , b)] - d[gcd(a , c)] + d[gcd(a , gcd(b , c))];
        D[2] = d[b] - d[gcd(a , b)] - d[gcd(b , c)] + d[gcd(a , gcd(b , c))];
        D[4] = d[c] - d[gcd(a , c)] - d[gcd(b , c)] + d[gcd(a , gcd(b , c))];
        D[3] = d[gcd(a , b)] - d[gcd(a , gcd(b , c))];
        D[5] = d[gcd(a , c)] - d[gcd(a , gcd(b , c))];
        D[6] = d[gcd(c , b)] - d[gcd(a , gcd(b , c))];
        D[7] = d[gcd(a , gcd(b , c))];


        VI CNT(7);
        int res = 0;

        FOR(mask1 , 1 , 8)
            FOR(mask2 , 1 , 8)
                FOR(mask3 , 1 , 8)
                {
                    if (!(mask1 & 1)) continue;
                    if (!(mask2 & 2)) continue;
                    if (!(mask3 & 4)) continue;

                    int val = D[mask1] * D[mask2] * D[mask3];

                    if (mask1 == mask2 )
                    {

                        val = D[mask1] * (D[mask1] + 1) / 2 * D[mask3];
                    }
                    if (mask1 == mask3 )
                    {
                        val = D[mask1] * (D[mask1] + 1) / 2 * D[mask2];
                    }
                    if (mask3 == mask2 )
                    {

                        val = D[mask2] * (D[mask2] + 1) / 2 * D[mask1];
                    }

                    if (mask1 == mask2 && mask1 == mask3)
                    {
                        val = D[mask1] * (D[mask1] + 1) * (D[mask1] + 2) / 6;
                    }





                    VI p(3);
                    p[0] = mask1;
                    p[1] = mask2;
                    p[2] = mask3;
                    sort(ALL(p));
                    int cnt = 0;
                    do{
                        if (!(p[0] & 1)) continue;
                        if (!(p[1] & 2)) continue;
                        if (!(p[2] & 4)) continue;
                        ++ cnt;
                    }while(next_permutation(ALL(p)));


                    CNT[cnt] += val;
                }

        FOR(i,1,7)
        {
            res += CNT[i] / i;
        }

        printf("%d\n" , res);

    }

}