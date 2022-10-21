#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)3e5 + 500;

int n,m;
int l,r,x;
int res[MAXN];
set<int> S;


int main(){
    scanf("%d%d", &n, &m);
    fill(res+1, res+1+n, 0);
    for(int i = 1; i <= n; i++) S.insert(i);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &l, &r, &x);
        auto it = S.lower_bound(l);
        while(it != S.end() && *it <= r){
            if(*it == x) it++;
            else{res[*it] = x; it = S.erase(it);}
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", res[i]);
}