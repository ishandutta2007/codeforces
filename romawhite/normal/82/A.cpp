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

const int INF = 1000000000;

int gcd(int a,int b){
    if (!b) return a;
    return gcd(b,a%b);
}

int a[1007];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    Int sz = 5;
    while (n > sz){
        n -= sz;
        sz *= 2;
    }
    if (n > 0 * sz / 5 && n <= 1 * sz / 5)
        cout << "Sheldon\n";
    if (n > 1 * sz / 5 && n <= 2 * sz / 5)
        cout << "Leonard\n";
    if (n > 2 * sz / 5 && n <= 3 * sz / 5)
        cout << "Penny\n";
    if (n > 3 * sz / 5 && n <= 4 * sz / 5)
        cout << "Rajesh\n";
    if (n > 4 * sz / 5 && n <= 5 * sz / 5)
        cout << "Howard\n";
    return 0;
}