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
const int MAX = 512;
const int MAX2 = 2000;
const int BASE = 1000000000;


int main()
{
    //freopen("in.txt","r",stdin);

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 <= x2 && y1 <= y2)
    {
        cout << "Polycarp" << endl;
        return 0;
    }

    int a = x1 + y1;
    int b = max(x2 , y2);

    if (a <= b)
    {
        cout << "Polycarp" << endl;
    }
    else
    {
        cout << "Vasiliy" << endl;
    }

    return 0;
}