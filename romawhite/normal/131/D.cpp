#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> g[3100];
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs (int v) {
    cl[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) 
    if (p[v]!=g[v][i])
    {
        int to = g[v][i];
        if (cl[to] == 0) {
            p[to] = v;
            if (dfs (to))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

int main() {
    int k,l,m,i,j;
    cin>>n;
    FOR(i,0,n){
               cin>>k>>l;
               g[k-1].PB(l-1);
               g[l-1].PB(k-1);
               }
    p.assign (n, -1);
    cl.assign (n, 0);
    cycle_st = -1;
    for (int i=0; i<n; ++i)
        if (dfs (i))
            break;
        vector<int> cycle;
        cycle.push_back (cycle_st);
                vector<int> res(n,-1);
                queue<int> q;
vector<bool> used (n);
vector<int> d (n), p1 (n);
        for (int v=cycle_end; v!=cycle_st; v=p[v])
            {
                 res[v]=0;
                 q.push(v);
                 used[v]=true;
                 p1[v]=-1;
                 }
                 int v1=cycle_st;
                 res[v1]=0;
                 q.push(v1);
                 used[v1]=true;
                 p1[v1]=-1;
   while (!q.empty()) {
    int v = q.front();
    if (res[v]!=0)
    res[v]=res[p1[v]]+1;
    q.pop();
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to]) {
            used[to] = true;
            q.push (to);
            d[to] = d[v] + 1;
            p1[to] = v;
        }
    }
}
FOR(i,0,n)
cout<<res[i]<<' ';
}