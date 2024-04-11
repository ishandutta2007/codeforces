#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,l[N],r[N],f[32];

int solve(int t){
    int len=1<<t,cnt=0;
    vector<pair<int,int> > dlt;
    for (int i=1;i<=n;++i){
        if (r[i]-l[i]+1>=len) ++cnt;
        else{
            int L=l[i]%len,R=r[i]%len;
            if (L<=R){
                dlt.push_back({L,1});
                dlt.push_back({R+1,-1});
            }
            else{
                dlt.push_back({0,1});
                dlt.push_back({R+1,-1});
                dlt.push_back({L,1});
            }
        }
    }
    sort(dlt.begin(),dlt.end());
    int ans=cnt,now=cnt;
    for (auto [x,y]:dlt){
        now+=y; ans=max(ans,now);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>l[i]>>r[i];
    }
    for (int t=0;t<=30;++t){
        f[t]=solve(t);
    }
    int m; cin>>m;
    while (m--){
        int x; cin>>x;
        int t=0; while (!(x>>t&1)) ++t;
        cout<<f[t]<<'\n';
    }

    return 0;
}