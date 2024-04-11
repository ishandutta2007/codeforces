#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int N=3228;
const int MOD=1000*1000*1000+7;

bool vv[100*1000+322];
vector<vector<int> > g(100*1000+322);
set<int> cats;

int dfs(int v,int ct,int mxc){
    int cnt=0;
    if(cats.count(v))
        ct++;
    else
        ct=0;
    if(ct>mxc)
        return 0;
    if(g[v].size() == 1 && v != 0){
        return 1;
    }
    vv[v]=1;
    for(auto &i: g[v]){
        if(!vv[i])
            cnt+=dfs(i,ct,mxc);
    }
    return cnt;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int ct;
        cin>>ct;
        if(ct)
            cats.insert(i);
    }
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }
    cout<<dfs(0,0,m)<<endl;
}




int main(){
    double tt=clock();

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //cout<<setprecision(20);
    //cout<<fixed;

    solve();

    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}