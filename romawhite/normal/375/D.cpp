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

int ptr[100007];
map<int, int> M[100007];
map<int, int> C[100007];
vector<int> g[100007];
vector<pair<int,int> > query[100007];

void insert(int a,int b){
    if (M[ptr[a]].size() < M[ptr[b]].size()){
        swap(ptr[a] , ptr[b]);
    }
    a = ptr[a];
    b = ptr[b];

    for(map<int,int>::iterator it = M[b].begin(); it != M[b].end(); ++it){
        int color = it->first;
        int cnt = it->second;
        int incnt = M[a][color];
        if (incnt != 0){
            C[a][incnt]--;
            if (C[a][incnt] == 0)
                C[a].erase(incnt);
        }
        M[a][color] += cnt;
        C[a][incnt + cnt]++;
    }
    M[b].clear();
    C[b].clear();
}

int res[100007];
bool used[100007];

int K;

void dfs(int v){
    used[v] = 1;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]]){
            dfs(g[v][i]);
            insert(v , g[v][i]);
        }

    FOR(i,0,query[v].size()){
        int k = query[v][i].first;
        if (k < K){
            int r = M[ptr[v]].size();
            for(map<int,int>::iterator it = C[ptr[v]].begin(); it != C[ptr[v]].end(); ++it){
                if (it->first >= k)
                    break;
                r -= it->second;
            }
            res[query[v][i].second] = r;
        }
        else{
            int r = 0;
            for(map<int,int>::reverse_iterator it = C[ptr[v]].rbegin(); it != C[ptr[v]].rend(); ++it){
                if (it->first < k)
                    break;
                r += it->second;
            }
            res[query[v][i].second] = r;
        }
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n,m;
    cin >> n >> m;
    
    K = (int)sqrt(1.0 * n);

    FOR(i,0,n)
        ptr[i] = i;

    FOR(i,0,n){
        int c;
        cin >> c;
        M[i][c]++;
        C[i][1]++;
    }

    FOR(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].PB(b);
        g[b].PB(a);
    }

    FOR(i,0,m){
        int v,k;
        cin >> v >> k;
        --v;
        query[v].PB(MP(k,i));
    }
    dfs(0);

    FOR(i,0,m)
        cout << res[i] << endl;

}