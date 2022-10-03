#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<29;
int cnt[MAX];
int ans=INF;
ll a,b;

void solve(ll nowh,ll noww,int t,int used){
    if(nowh>=a&&noww>=b){
        chmin(ans,used);
        return;
    }
    if(used>=ans) return;
    if(t==1) return;
    if(cnt[t]==0){
        solve(nowh,noww,t-1,used);
        return;
    }
    
    ll h=nowh,w=noww;
    int ne1=0,ne2=0;
    while(h<a){
        ne1++;
        h*=t;
    }
    while(w<b){
        ne2++;
        w*=t;
    }
    if(ne1+ne2<=cnt[t]){
        chmin(ans,used+ne1+ne2);
        return;
    }
    
    ll kake1=1,kake2=1;
    for(int i=min(cnt[t],ne1);i>=0;i--){
        int j=cnt[t]-i;
        if(j>ne2) break;
        
        if(i==min(cnt[t],ne1)){
            for(int k=0;k<i;k++) kake1*=t;
            for(int k=0;k<j;k++) kake2*=t;
        }else{
            kake1/=t;
            kake2*=t;
        }
        solve(nowh*kake1,noww*kake2,t-1,used+cnt[t]);
    }
    
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h,w,N;cin>>a>>b>>h>>w>>N;
    
    for(int i=0;i<N;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    
    solve(h,w,100000,0);
    solve(w,h,100000,0);
    
    if(ans==INF) ans=-1;
    
    cout<<ans<<endl;
    
}