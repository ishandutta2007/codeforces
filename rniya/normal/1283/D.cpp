#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    map<int,int> cnt;
    queue<int> que;
    for (int i=0;i<n;++i){
        int x; cin >> x;
        cnt[x]=0; que.emplace(x);
    }
    ll ans=0;
    const int dx[2]={-1,1};
    vector<int> pos;
    while(!que.empty()&&pos.size()<m){
        int x=que.front(); que.pop();
        for (int i=0;i<2;++i){
            int nx=x+dx[i];
            if (cnt.count(nx)) continue;
            cnt[nx]=cnt[x]+1; ans+=cnt[nx];
            pos.emplace_back(nx); que.emplace(nx);
            if (pos.size()==m) break;
        }
    }
    cout << ans << '\n';
    for (int i=0;i<m;++i) cout << pos[i] << (i!=m-1?' ':'\n');
}