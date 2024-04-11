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
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define For(i, a, b) for(int i=(a);i<(b);i++)
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
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 200000;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 2000;

int res[MAX];

int main()
{   
    //freopen("in.txt","r",stdin);
    
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        res[i] = INF;
    }
    
    int c = 1;
    FOR(i,0,n)
    {
        c = min(c , a[i] - i);
        res[i] = min(res[i] , c + i);
    }
    
    c = n;
    RFOR(i,n,0)
    {
        c = min(c , a[i] + i);
        res[i] = min(res[i] , c - i);
    }
    
    int R = 0;
    FOR(i,0,n)
    {
        R = max(R , res[i]);
    }
    
    /*FOR(i,0,n)
    {
        cout << res[i] << ' ';
    }
    cout << endl;*/
    
    cout << R << endl;
}