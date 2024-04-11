#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;


int main()
{
      //freopen("in.txt","r",stdin);

    int n , k;
    cin >> n >> k;
    k = n - k;
    int a = 0;
    int b = 0;

    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        if (x % 2 == 0)
        {
            ++a;
        }
        else
        {
            ++b;
        }
    }
    
    if (k == 0 && b % 2 == 1)
    {
        cout << "Stannis" << endl;
        return 0;
    }

    if (k % 2 == 1)
    {
        if (k / 2 >= a && (n - k) % 2 == 0)
        {
            cout << "Daenerys" << endl;
            return 0;
        }
        if (k / 2 >= b)
        {
            cout << "Daenerys" << endl;
            return 0;
        }

        cout << "Stannis" << endl;
        return 0;
    }

    if (k / 2 >= a && (n - k) % 2 == 1)
    {
        cout << "Stannis" << endl;
        return 0;
    }

    cout << "Daenerys" << endl;


    return 0;
}