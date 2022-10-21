#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;
typedef pair<int, int> P;

int n, m, a, b, num[MAXN], ans[MAXN];
vector<P> qry[MAXN];
vector<int> pre[MAXN];

int bit[MAXN];

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i, int val){
    while(i < MAXN){bit[i] += val; i += (i&-i);}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        qry[b].push_back({a, i});
    }
    for(int i = 1; i <= n; i++){
        int t = num[i];
        if(t <= (int)1e5){
            pre[t].push_back(i);
            int sz = pre[t].size();
            if(sz >= t) add(pre[t][sz-t], 1);
            if(sz > t) add(pre[t][sz-t-1], -2);
            if(sz > t+1) add(pre[t][sz-t-2], 1);
        }

        int now = get(i);
        for(P p : qry[i]){
            ans[p.second] = now;
            if(p.first > 1) ans[p.second] -= get(p.first-1);
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }

}