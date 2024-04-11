#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef pair <int, int> PII;

int a[200007];

int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/
    
    int n;
    cin >> n;
    a[0] = 0;
    LL s = 0;
    int cnt = 1;

    FOR(query,0,n){
        int t;
        scanf("%d" , &t);
        if (t == 1){
            int k,x;
            scanf("%d%d" , &k , &x);
            a[k - 1] += x;
            s += k * x;
        }
        if (t == 2){
            int k;
            scanf("%d" , &k);
            a[cnt] = k;
            a[cnt - 1] = a[cnt - 1] - a[cnt];
            s += k;
            cnt++;
        }
        if (t == 3){
            a[cnt - 2] += a[cnt - 1];
            s -= a[cnt - 1];
            cnt--;
        }
        printf("%.10f\n" , 1.0 * s / cnt);
    }
    


    return 0;
}