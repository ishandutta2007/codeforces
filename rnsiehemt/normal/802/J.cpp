#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;

int n;
vector<pair<int,int>> al[123];
int ans;

void go(int at, int par, int cc) {
    ans = max(ans, cc);
    for (auto x : al[at]) if (x.first != par) go(x.first, at, cc + x.second);   
}
int main() {
    scanf("%d", &n);
    fo(i,0,n-1) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        al[u].pb({v,d});
        al[v].pb({u,d});
    }
    go(0,-1, 0);
    printf("%d\n", ans);

    return 0;
}