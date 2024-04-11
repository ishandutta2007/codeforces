#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n,m,q,a,b;
vector<int> row[N];
set<int> S[N], tot;
int f[N], fir[N];

int find(int i){return f[i] == i ? i : f[i] = find(f[i]);}
int unite(int i, int j){int fi = find(i), fj = find(j); f[fi] = fj;}

int main(){
    fill(fir, fir+N, -1);
    for(int i = 0; i < N; i++) f[i] = i;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        row[a].push_back(b);
        tot.insert(b);
        if(fir[b] == -1) fir[b] = a;
        else unite(fir[b], a);
    }
    for(int i = 0; i < n; i++){
        int fi = find(i);
        for(int x : row[i]){
            S[fi].insert(x);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(find(i) == i){
            res++;
        }
    }
    res--;
    res += (m - tot.size());
    cout << res << endl;
}