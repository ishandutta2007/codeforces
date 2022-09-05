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
#include <fstream>
#include <time.h>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

#define distance sgfsdfgs

typedef long long Int;
typedef unsigned int uint;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MAX = 2048;
const int MAX2 = 1000007;
const int MOD = 1000000007;

vector<int> a;

int main()
{
//#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
//#endif
    int k;
    cin >> k;

    if (k < 64){
        vector<int> a;
        for(int i = 2;i <= 2 * k * k; ++i){
            int x = i;
            while (x % 2 == 0)
                x /= 2;
            while (x % 3 == 0)
                x /= 3;
            if (x == 1)
                a.PB(i);
        }

        RFOR(i,a.size(),a.size()-k)
            cout << a[i] << ' ';
        return 0;

    }

    if (k < 400){
        vector<int> a;
        for(int i = 2;i <= 2 * k * k; ++i){
            int x = i;
            while (x % 2 == 0)
                x /= 2;
            while (x % 3 == 0)
                x /= 3;
            while (x % 5 == 0)
                x /= 5;
            if (x == 1)
                a.PB(i);
        }

        RFOR(i,a.size(),a.size()-k)
            cout << a[i] << ' ';
        return 0;

    }

    if (k < 2000){
        vector<int> a;
        for(int i = 2;i <= 2 * k * k; ++i){
            int x = i;
            while (x % 2 == 0)
                x /= 2;
            while (x % 3 == 0)
                x /= 3;
            while (x % 5 == 0)
                x /= 5;
            while(x % 7 == 0)
                x /= 7;
            if (x == 1)
                a.PB(i);
        }

        RFOR(i,a.size(),a.size()-k)
            cout << a[i] << ' ';
        return 0;

    }

    vector<int> a;
    for(int i = 2;i <= 2 * k * k; ++i){
        int x = i;
        while (x % 2 == 0)
            x /= 2;
        while (x % 3 == 0)
            x /= 3;
        while (x % 5 == 0)
            x /= 5;
        while(x % 7 == 0)
            x /= 7;
        while(x % 11 == 0)
            x /= 11;
        if (x == 1)
            a.PB(i);
    }


    RFOR(i,a.size(),a.size()-k)
            cout << a[i] << ' ';

}