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
#include <assert.h>
#include <time.h>


#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<Int, Int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 200007;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int A[MAX];

int S[4 * MAX];
int M[4 * MAX];

void upd(int v, int l, int r, int pos , int val)
{
    if (l == r)
    {
        S[v] = val;
        M[v] = max(val , 0);
        return;
    }
    
    int m = (l + r) / 2;
    if (pos <= m)
        upd(2 * v + 1 , l , m , pos , val);
    else
        upd(2 * v + 2 , m + 1 , r , pos , val);
    S[v] = S[2 * v + 1] + S[2 * v + 2];
    M[v] = max(M[2 * v + 2] , S[2 * v + 2] + M[2 * v + 1]);
}

int get(int v, int l, int r, int val)
{
    if (l == r)
    {
        return A[l];
    }
    int m = (l + r) / 2;
    
    
    if (M[2 * v + 2] >= val)
    {
        return get(2 * v + 2 , m + 1 , r , val);
    }
    else
    {
        return get(2 * v + 1 , l , m , val - S[2 * v + 2]);
    }
}

int main()
{
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
    
    int n;
    cin >> n;
    
    FOR(i,0,n)
    {
        int p , t;
        scanf("%d%d", &p , &t);
        -- p;
        if (t == 1)
        {
            int x;
            scanf("%d", &x);
            A[p] = x;
        }
        if (t == 1)
            upd(0,0,n - 1 , p , 1);
        else    
            upd(0,0,n - 1 , p , -1);
        int res = -1;
        if (M[0] >= 1)
            res = get(0,0,n - 1 , 1);
        printf("%d\n", res);
    }
    
    return 0;
}