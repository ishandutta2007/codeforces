#include<bits/stdc++.h>
using namespace std;
const int NN = 5e5+10;
//const int NN = 5+10;



int head[NN], nxt[NN<<1], to[NN<<1], wei[NN<<1];
int n, k, E;
using LL = long long;
LL dp[NN][2];

void init() {
    for(int i=1; i<=n; i++) head[i]=-1;
    E=0;
}

void add(int u, int v, int w) {
    nxt[E]=head[u];
    to[E]=v;
    wei[E]=w;
    head[u]=E++;

    nxt[E]=head[v];
    to[E]=u;
    wei[E]=w;
    head[v]=E++;
}

using VI = vector<LL>;

void dfs(int u, int fa=0) {
    VI arr;
    LL tot=0;
    for(int e=head[u]; ~e; e=nxt[e]) {
        int v=to[e];
        if(v == fa) continue;
        dfs(v, u);
        tot+=dp[v][0];
        arr.push_back(dp[v][1]+wei[e]-dp[v][0]);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    LL tmp=0;
    for(int i=0; i<k && i<arr.size(); i++) {
        if(arr[i]>0) tmp+=arr[i];
    }
    dp[u][0]=tot+tmp;
    tmp=0;
    for(int i=0; i<k-1 && i<arr.size(); i++) {
        if(arr[i]>0) tmp+=arr[i];
    }
    dp[u][1]=tot+tmp;
}

void solve() {
    scanf("%d %d", &n, &k);
    init();
    for(int i=1, u, v, w; i<n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dfs(1);
    //for(int i=1; i<=n; i++) cout<<dp[i][0]<<' '<<dp[i][1]<<endl;puts("");

    printf("%I64d\n", max(dp[1][0], dp[1][1]));
}

int main() {
    //freopen("E.in", "r", stdin);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}