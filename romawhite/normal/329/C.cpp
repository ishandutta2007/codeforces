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

vector<int> g[100007];
map<pair<int,int> , int > M;

int q[100007];
bool used[100007];

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/
    //freopen("out.txt" , "w" , stdout); 
    int n,m;
    cin >> n >> m;
    FOR(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].PB(b);
        g[b].PB(a);
        M[MP(a,b)] = 1;
        M[MP(b,a)] = 1;
    }
    if (n <= 6){
        vector<pair<int,int> >  A;
        int k = n * (n - 1) / 2;
        FOR(i,0,n)
            FOR(j,i + 1 , n)
            A.PB(MP(i,j));
        int c[22];
        bool found = 0;
        FOR(mask,0,1 << A.size()){
            FILL(c,0);
            int mm = 0;
            bool ok = 1;
            FOR(i,0,A.size())
                if (mask & (1 << i)){
                    ++mm;
                    int a = A[i].first;
                    int b = A[i].second;
                    if (M[MP(a,b)])
                        ok = 0;
                    c[a]++;
                    c[b]++;
                }
            if (mm != m)
                ok = 0;
            FOR(i,0,n)
                if (c[i] > 2)
                    ok = 0;
            if (ok){
                found = 1;
                FOR(i,0,A.size())
                    if (mask & (1 << i))
                        cout << A[i].first + 1 << ' ' << A[i].second + 1 << endl;
                break;
            }
        }
        if (!found){
            cout << -1 << endl;
        }
        return 0;
    }

    int l = 0;
    int r = 0;

    FOR(i,0,n)
        if (!used[i]){
            used[i] = true;
            q[r++] = i;
            while (r > l){
                int v = q[l++];
                FOR(i,0,g[v].size())
                    if(!used[g[v][i]]){
                        used[g[v][i]] = true;
                        q[r++] = g[v][i];
                    }
            }
        }
    FOR(i,0,m){
        cout << q[i] + 1 << ' ' << q[(i + 3) % n] + 1 << endl; 
    }

    return 0;
}