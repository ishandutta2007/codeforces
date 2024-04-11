#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll c[3][100002];
    for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) cin >> c[i][j];
    vector<int> g[100002];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l = -1;
    for(int i = 0; i < n; i++){
        if((int)g[i].size() >= 3){
            cout << -1 << endl;
            return 0;
        }
        if((int)g[i].size() == 1) l = i;
    }
    ll ans = 100000000000000000;
    ll argcol = -1;
    for(int col = 0; col < 6; col++){
        ll sum = 0;
        bool used[100002];
        fill(used, used + n, false);
        int now = l;
        int ncol = col % 3;
        while(true){
            used[now] = true;
            sum += c[ncol][now];
            int next = -1;
            for(int i = 0; i < (int)g[now].size(); i++){
                if(!used[g[now][i]]) next = g[now][i];
            }
            if(next == -1) break;
            now = next;
            if(col < 3) ncol = (ncol + 1) % 3;
            else ncol = (ncol + 2) % 3;
        }
        if(sum < ans){
            ans = sum;
            argcol = col;
        }
    }
    cout << ans << endl;
    int ansc[100002];
    bool used[100002];
    fill(used, used + n, false);
    int now = l;
    int ncol = argcol % 3;
    while(true){
        used[now] = true;
        ansc[now] = ncol + 1;
        int next = -1;
        for(int i = 0; i < (int)g[now].size(); i++){
            if(!used[g[now][i]]) next = g[now][i];
        }
        if(next == -1) break;
        now = next;
        if(argcol < 3) ncol = (ncol + 1) % 3;
        else ncol = (ncol + 2) % 3;
    }
    for(int i = 0; i < n; i++) cout << ansc[i] << " ";
    cout << endl;
}