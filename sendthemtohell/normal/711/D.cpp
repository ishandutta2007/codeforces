#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair

int h[200*1000];
int vv[200*1000];
const int MOD=1000*1000*1000+7;
vector<vector<int> > G(200*1000);

pair<int,int> dfs(int v,int rec){
    vv[v]=rec;
    rec++;
    int num=1,loop=2;
    for(auto &u: G[v]){
        if(!vv[u]){
            pair<int,int> tmp=dfs(u,rec);
            num+=tmp.first;
            loop=max(loop,tmp.second);
        }else if(loop==2){
            loop=abs(vv[v]-vv[u])+1;
        }
    }
    return mp(num,loop);
}

ll pw(int power){
    ll res=1;
    ll base=2;
    while(power){
            if(power&1){
                res *= base;
                res %= MOD;
            }
            base *= base;
            base %= MOD;
            power >>= 1;
    }
    return res;
}

void solve(){
    int n;
    ll vars=1;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>h[i];
    for(int i=0;i<n;++i){
        G[i].pb(h[i]-1);
        G[h[i]-1].pb(i);
    }
    for(int i=0;i<n;++i){
        if(!vv[i]){
            pair<int,int> tmp=dfs(i,1);
            //cout<<tmp.first<<"  "<<tmp.second<<endl;
            //cout<<pw(tmp.second)-2<<"  "<<pw(tmp.first-tmp.second)<<endl;
            ll part=(pw(tmp.second)-2)*(pw(tmp.first-tmp.second));
            part %= MOD;
            vars *= part;
            vars %= MOD;
        }
    }
    cout<<vars<<endl;
}





int main(){
    double tt=clock();
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
    ios_base::sync_with_stdio(false);
    //cout<<setprecision(20);
    //cout<<fixed;
    solve();
    #ifdef LOCAL
        cout<<"Time: "<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}