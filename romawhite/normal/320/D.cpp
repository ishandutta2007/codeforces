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
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MOD = 1000000007;

int a[100007];
int l[100007];
int r[100007];
int killed[100007];
int time = 1;

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n;
    cin >> n;
    FOR(i,0,n)
        cin >> a[i];

    FOR(i,0,n - 1)
        r[i] = i + 1;
    FOR(i,1,n)
        l[i] = i - 1;
    l[0] = r[n - 1] = -1;


    set<int> s;
    int res = 0;
    FOR(i,0,n - 1)
        if (a[i + 1] < a[i]){
            s.insert(i + 1);
            killed[i + 1] = 1;
        }
    
    while (1){
        if (s.size() == 0)
            break;
        ++res;
        ++time;
        set<int> ss;
        for(auto it = s.begin();it != s.end(); ++it){
            int i = *it;
            //cout << i << ' ';
            int L = l[i];
            int R = r[i];
            if (R != -1)
                l[R] = L;
            if (L != -1)
                r[L] = R;
            if (L != -1 && R != -1 && (!killed[L] || killed[L] == time) && !killed[R] && a[L] > a[R]){
                ss.insert(R);
                killed[R] = time;
            }
        }
        s = ss;
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}