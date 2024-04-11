#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;


char a[MAX];
char b[MAX];

map<string, int> M;

vector<int> C;

void f(int l, int r)
{
    if (l == r) return;
    int m = (l + r) / 2;
    f(l, m);
    f (m + 1, r);
    bool gr = 0;
    FOR(i,l,m + 1)
    {
        if (C[i] > C[i - l + m + 1])
        {
            gr = 1;
            break;
        }
        if (C[i] < C[i - l + m + 1])
        {
            break;
        }
    }
    if (gr)
    {
        FOR(i,l,m + 1)
        {
            swap(C[i] , C[i - l + m + 1]);
        }
    }
}

int main()
{
    //freopen("in.txt" , "r", stdin);
    
    scanf("%s" , &a);
    scanf("%s" , &b);
    int n = strlen(a);
    
    int l = n;
    while (l % 2 != 1) l /= 2;
    vector<int> A, B;
    for(int i = 0; i < n; i += l)
    {
        string t = "";
        FOR(j,0,l)
            t += a[i + j];
        if (!M.count(t))
        {
            int sz = M.size();
            M[t] = sz;
        }
        A.push_back(M[t]);
    }
    for(int i = 0; i < n; i += l)
    {
        string t = "";
        FOR(j,0,l)
        t += b[i + j];
        if (!M.count(t))
        {
            int sz = M.size();
            M[t] = sz;
        }
        B.push_back(M[t]);
    }
    C = A;
    f(0,C.size() - 1);
    A = C;
    C = B;
    f(0,C.size() - 1);
    B = C;
    //cout << A[0] << ' ' << B[0] << endl;
    if (A == B)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        
    }
    
    return 0;
}