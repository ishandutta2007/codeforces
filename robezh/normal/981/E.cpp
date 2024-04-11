#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
typedef bitset<N> bs;

int n,q,l,r,x;
vector<int> add[4*N];
bs ans;

void add_seg(int a, int b, int v){
    if(b < l || r < a) return ;
    if(l <= a && b <= r){
        add[v].push_back(x);
        return ;
    }
    int mid = (a + b) / 2;
    add_seg(a, mid, v*2+1);
    add_seg(mid+1, b, v*2+2);
}

void dfs(int a, int b, int v, bs dp){
    bs go = dp;

    for(int x : add[v])
        go |= (go << x);

    if(a == b) {
        ans |= go;
        return ;
    }

    int mid = (a + b) / 2;
    dfs(a, mid, v*2+1, go);
    dfs(mid+1, b, v*2+2, go);
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        cin >> l >> r >> x;
        l--, r--;
        add_seg(0,n-1,0);
    }
    bs dp;
    dp[0] = 1;
    dfs(0,n-1,0,dp);

    vector<int> res;
    for(int i = 1; i <= n; i++) if(ans[i]) res.push_back(i);

    cout << res.size() << endl;
    for(int x : res) cout << x << " ";

}