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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
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
typedef pair <double, double> PDD;

const int INF = 1000000000;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MAX = 1000007;

int t[MAX];
int p[MAX];
int n;

void init (int nn)
{
    n = nn;
    FILL(t,0);
}

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    
    
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &p[i]);
        -- p[i];
    }
    
    Int inv = 0;
    FOR(i,0,n)
    {
        inv += (i - sum(p[i]));
        inc(p[i] , 1);
    }
    
    
    if (n % 2 == inv % 2)
    {
        cout << "Petr" << endl;
    }
    else
    {
        cout << "Um_nik" << endl;
    }
    
    
    
    
    

    return 0;
}