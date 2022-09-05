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
typedef long double LD;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;

string s[107];

vector<int> a[107];
vector<int> b[107];

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n;
    cin >> n;

    FOR(i,0,n)
        cin >> s[i];

    FOR(i,0,n){
        FOR(j,0,n)
            if (s[i][j] != 'E'){
                a[i].PB(j);
                break;
            }
    }

    FOR(j,0,n){
        FOR(i,0,n){
            if (s[i][j] != 'E'){
                b[j].PB(i);
                break;
            }
        }
    }

    bool q = 1;
    FOR(i,0,n){
        if (a[i].empty())
            q = 0;
    }

    if (q){
        FOR(i,0,n)
            cout << i + 1 << ' ' << a[i][0] + 1 << endl;
        return 0;
    }

    q = 1;
    FOR(i,0,n){
        if (b[i].empty())
            q = 0;
    }

    if (q){
        FOR(i,0,n)
            cout << b[i][0] + 1 << ' ' << i + 1 << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}