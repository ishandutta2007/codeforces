#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>

using namespace std;

//#define HOME
#define mp make_pair
#define pb push_back
#define prev _prev
#define rank _rank

typedef long long ll;
typedef pair <ll, int> pli;

const ll inf = (ll)1e15;

struct edge{
    int a, b;
    ll c;
};

ll d[100100];
int col[100100], prev[100100], rank[100100];
edge e[200200];
vector <int> v[100100], w[100100];

bool operator < (const edge &a, const edge &b){
    return a.c < b.c;
}

int get(int a){
    if(prev[a] != a){
        prev[a] = get(prev[a]);
    }
    return prev[a];
}

inline void merge(int a, int b){
    if(rank[a] == rank[b]){
        prev[b] = a;
        rank[a]++;
        return;
    }
    if(rank[a] < rank[b]){
        prev[a] = b;
        return;
    }
    prev[b] = a;
}

int main(){
#ifndef HOME
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout); 
#else
    double start = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        v[a].pb(b);
        w[a].pb(c);
        v[b].pb(a);
        w[b].pb(c);
    }
    set <pli> s;
    for(int i = 0; i < n; i++){
        d[i] = inf;
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int num;
        scanf("%d", &num);
        num--;
        d[num] = 0;
        col[num] = num;
    }
    for(int i = 0; i < n; i++){
        s.insert(mp(d[i], i));
    }
    while(!s.empty()){
        pli cur = *(s.begin());
        s.erase(s.begin());
        for(int i = 0; i < (int)v[cur.second].size(); i++){
            int to = v[cur.second][i];
            if(d[to] > d[cur.second] + w[cur.second][i]){
                s.erase(mp(d[to], to));
                d[to] = d[cur.second] + w[cur.second][i];
                col[to] = col[cur.second];
                s.insert(mp(d[to], to));
            }
        }
    }
    int edges = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int)v[i].size(); j++){
            if(col[i] != col[v[i][j]]){
                e[edges].a = col[i];
                e[edges].b = col[v[i][j]];
                e[edges++].c = d[i] + d[v[i][j]] + w[i][j];
            }
        }
    }
    ll ans = d[0];
    sort(e, e + edges);
    for(int i = 0; i < n; i++){
        prev[i] = i;
        rank[i] = 1;
    }
    for(int i = 0; i < edges; i++){
        int a = get(e[i].a), b = get(e[i].b);
        if(a != b){
            ans += e[i].c;
            merge(a, b);
        }
    }
    printf("%I64d\n", ans);
#ifdef HOME
    printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}