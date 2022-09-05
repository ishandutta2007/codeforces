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


int main()
{
#ifndef ONLINE_JUDGE
//  freopen("in.txt" , "r" , stdin);
#endif

    string s = "";

    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i,0,n){
        cin >> a[i];
    }

    FOR(i,0,157){
        FOR(j,0,n - 1)
            s += 'R';
        s += 'L';
        s += 'R';
        FOR(j,0,n - 1)
            s += 'L';
        s += 'R';
        s += 'L';
    }

    string res = "";
    int ind = 0;
    FOR(i,0,s.size()){
        res += s[i];
        if (s[i] == 'R')
            ++ind;
        else --ind;
        if (a[ind] > 0){
            res += 'P';
            a[ind]--;
        }
    }

    cout << res << endl;

}