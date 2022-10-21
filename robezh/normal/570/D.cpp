#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500;

int n,m,t,a,b,cur = 0;
vector<int> G[N];
string str;
vector<int> pos[N];
vector<int> num[N];
vector<int> dat[N];
int depth[N], mxdepth[N], loc[N], pw2[30];
int cont[2 * N], st[N], ed[N];
bool vis[N];

int count_1(int x){
    int cnt = 0;
    while(x > 0){
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

void dfs(int v, int d){
    vis[v] = true;
    st[v] = cur, cont[cur++] = v;
    loc[v] = num[d].size(); num[d].push_back(v);
    pos[d].push_back(cur-1);
    depth[v] = mxdepth[v] = d;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            dfs(nxt, d+1);
            mxdepth[v] = max(mxdepth[v], mxdepth[nxt]);
        }
    }
    ed[v] = cur, cont[cur++] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    pw2[0] = 1;
    for(int i = 1; i < 26; i++){pw2[i] = pw2[i-1] * 2;}

    cin >> n >> m;
    for(int i = 1; i <= n-1; i++){
        cin >> a; a--;
        G[a].push_back(i);
        G[i].push_back(a);
    }
    cin >> str;

    fill(vis, vis+n, false);
    dfs(0, 0);
    for(int i = 0; i < n; i++) {
        if(!num[i].empty()){
            dat[i].push_back(pw2[str[num[i][0]] - 'a']);
            for(int j = 1; j < num[i].size(); j++) {
                int nxt = (pw2[str[num[i][j]] - 'a']) ^ (dat[i][j-1]);
                dat[i].push_back(nxt);
            }
        }
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        if(depth[a] > b || mxdepth[a] < b){
            cout << "Yes" << endl;
        }
        else{
            int l = lower_bound(pos[b].begin(), pos[b].end(), st[a]) - pos[b].begin();
            int r = upper_bound(pos[b].begin(), pos[b].end(), ed[a]) - pos[b].begin() - 1;
            //cout << "l, r, size : " << l << " " << r << " " << pos[b].size() << endl;
            int res = (dat[b][r]) ^ (l == 0 ? 0 : dat[b][l-1]);
            if(count_1(res) <= 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    };
}