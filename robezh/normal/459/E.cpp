#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500;
typedef pair<int, int> P;

int n,m,a,b,l;
int dis[N];
vector<P> E[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> l;
        a--, b--;
        E[l].push_back({a, b});
    }
    for(int i = 1; i <= (int)3e5; i++){
        vector<P> nxt;
        for(P p : E[i]) nxt.push_back({p.second, dis[p.first]+1});
        for(P p : nxt) dis[p.first] = max(dis[p.first], p.second);
    }
    int res = 0;
    for(int i = 0; i < n; i++){res = max(res, dis[i]);}
    cout << res;
}