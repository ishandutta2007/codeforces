#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#include <complex>
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
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 2000003;
const int CNT = 1000;

int a[MAX];
int b[MAX];
int c[MAX];
int r[MAX];

int main()
{
   //freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int m , k;
        scanf("%d%d" , &m , &k);
        --m;
        FOR(i,0,k)
        {
            b[i] = 0;
        }
        FOR(i,0,k)
        {
            scanf("%d" , &a[i]);
        }
        int cnt = 0;
        FOR(i,0,m)
        {
            scanf("%d%d" , &c[i] , &r[i]);
            r[i] ^= 1;
            --c[i];
            if (c[i] == -1) ++cnt;
            
        }
        int id = -1;
        FOR(i,0,m)
        {
            if (r[i] == 0)
            {
                id = i;
                break;
            }
        }
        //cout << id << endl;
        int rr = 0;
        if (id != -1)
        {
            FOR(i,id,m)
            {
                if (c[i] != -1)
                {
                    b[c[i]]++;
                }
            }
            int c1 = 0;
            FOR(i,0,id)
            {
                if (c[i] >= 0)
                    a[c[i]]--;
                else
                    ++c1;
            }
            rr = INF;
            FOR(i,0,k)
            {
                if (b[i] == 0)
                {
                    rr = min(rr , a[i]);
                }
            }
            FOR(i,0,k)
            {
                if ((b[i] == 0 && a[i] <= c1) || a[i] - b[i] + rr <= cnt)
                {
                    printf("Y");
                }
                else printf("N");
            }
            printf("\n");
        }
        else
        {
            FOR(i,0,m)  
            {
                if (c[i] >= 0)
                {
                    a[c[i]]--;
                }
            }
            FOR(i,0,k)
            {
                if (a[i] <= cnt)
                {
                    printf("Y");
                }
                else printf("N");
            }
            printf("\n");
        }
    }
    

    return 0;
}