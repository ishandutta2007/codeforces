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

char s[1000007];

vector<int> a[4000007];
int b[4000007];
vector<int> temp;

void build(int v,int l, int r){
    if (l == r){
        if (s[l] == '(')
            b[v] = 1;
        else{
            a[v].PB(1);
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1 , l , m);
    build(2 * v + 2 , m + 1 , r);

    b[v] = b[2 * v + 1] + b[2 * v + 2];


    {
        temp.clear();
        int i = 0;
        int x = b[2 * v + 1];
        FOR(j,0,a[2 * v + 2].size()){
            while (i < a[2 * v + 1].size() && a[2 * v + 1][i] <= max(a[2 * v + 2][j] - x , 0)){
                ++i;
                --x;
            }
            temp.PB(max(0 , a[2 * v + 2][j] - x) );
        }   
    }


    int i = 0;
    int j = 0;

    while (i < a[2 * v + 1].size() || j < temp.size()){
        if (i == a[2 * v + 1].size()){
            a[v].PB(temp[j++]);
            continue;
        }
        if (j == temp.size()){
            a[v].PB(a[2 * v + 1][i++]);
            continue;
        }
        int v1 = a[2 * v + 1][i];
        int v2 = temp[j];
        if (v1 < v2){
            ++i;
            a[v].PB(v1);
        }
        else{
            ++j;
            a[v].PB(v2);
        }
    }
}

int c;
int sub;

void f(int v,int l , int r , int L , int R){
    if (l == L &&  r == R){
        int t = upper_bound(ALL(a[v]) , c) - a[v].begin();
        sub += t;
        c += b[v] - t;
        return;
    }
    int m = (l + r) / 2;
    if (L <= m)
        f(2 * v + 1 , l , m , L , min(R , m) );
    if (R > m)
        f(2 * v + 2 , m + 1 , r , max(L , m + 1) , R);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    scanf("%s" , s);
    int n = strlen(s);

    /*int n = 1000000;
    FOR(i,0,n)
        s[i] = (rand() % 2 ? '(' : ')');*/

    build(0,0,n - 1);

    int m;
    cin >> m;
    //m = 100000;
    FOR(i,0,m){
        int l,r;
        scanf("%d%d" , &l , &r);
        /*l = rand() % 1000000 + 1;
        r = rand() % 1000000 + 1;
        if (l > r)
            swap(l,r);*/
        
        --l;--r;
        c = 0;
        sub = 0;
        f(0,0,n - 1 , l , r);
        cout << 2 * sub << endl;
    }

}