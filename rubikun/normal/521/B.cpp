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
const int mod=1000000009,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<int,int>> pos(N);
    map<pair<int,int>,int> MA;
    set<int> can;
    
    for(int i=0;i<N;i++){
        int x,y;cin>>x>>y;
        MA[mp(x,y)]=i;
        pos[i]=mp(x,y);
    }
    
    auto check=[&](int x,int y){
        for(int i=x-1;i<=x+1;i++){
            if(MA.count(mp(i,y+1))){
                bool ok=false;
                for(int j=i-1;j<=i+1;j++){
                    if(x==j) continue;
                    if(MA.count(mp(j,y))) ok=true;
                }
                if(!ok) return false;
            }
        }
        return true;
    };
    
    for(auto a:MA){
        int x=a.fi.fi,y=a.fi.se;
        if(check(x,y)) can.insert(a.se);
    }
    
    ll ans=0;
    
    for(int t=0;t<N;t++){
        ans*=N;
        ans%=mod;
        if(t%2==0){
            auto it=*can.rbegin();
            ans+=it;
            ans%=mod;
            can.erase(it);
            MA.erase(pos[it]);
            for(int i=pos[it].fi-2;i<=pos[it].fi+2;i++){
                for(int j=pos[it].se-2;j<=pos[it].se+2;j++){
                    if(MA.count(mp(i,j))&&can.count(MA[mp(i,j)])) can.erase(MA[mp(i,j)]);
                }
            }
            
            for(int i=pos[it].fi-2;i<=pos[it].fi+2;i++){
                for(int j=pos[it].se-2;j<=pos[it].se+2;j++){
                    if(MA.count(mp(i,j))&&check(i,j)) can.insert(MA[mp(i,j)]);
                }
            }
        }else{
            auto it=*can.begin();
            ans+=it;
            ans%=mod;
            can.erase(it);
            MA.erase(pos[it]);
            for(int i=pos[it].fi-2;i<=pos[it].fi+2;i++){
                for(int j=pos[it].se-2;j<=pos[it].se+2;j++){
                    if(MA.count(mp(i,j))&&can.count(MA[mp(i,j)])) can.erase(MA[mp(i,j)]);
                }
            }
            
            for(int i=pos[it].fi-2;i<=pos[it].fi+2;i++){
                for(int j=pos[it].se-2;j<=pos[it].se+2;j++){
                    if(MA.count(mp(i,j))&&check(i,j)) can.insert(MA[mp(i,j)]);
                }
            }
        }
    }
    
    cout<<ans<<endl;
}