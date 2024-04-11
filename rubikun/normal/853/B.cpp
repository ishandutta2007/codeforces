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
const int mod=1000000007,MAX=3005;
const ll INF=1LL<<40;
struct dat{
    int day;
    int from;
    int to;
    ll cost;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    
    vector<dat> S(M);
    for(int i=0;i<M;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;c--;
        S[i]=dat{a,b,c,d};
    }
    sort(all(S),[](auto a,auto b){
        return a.day<b.day;
    });
    
    vector<ll> left(N,INF),right(N,INF),minileft(1000000,INF),miniright(1000000,INF);
    int cnt=0;
    int id=0;
    ll sum=INF*N;
    
    for(int i=0;i<1000000;i++){
        while(id<M&&S[id].day==i){
            if(S[id].from!=-1){
                if(left[S[id].from]==INF){
                    cnt++;
                }
                sum-=left[S[id].from];
                chmin(left[S[id].from],S[id].cost);
                sum+=left[S[id].from];
            }
            id++;
        }
        if(cnt==N) chmin(minileft[i],sum);
    }
    
    reverse(all(S));
    cnt=0;
    id=0;
    sum=INF*N;
    
    for(int i=999999;i>=0;i--){
        while(id<M&&S[id].day==i){
            if(S[id].to!=-1){
                if(right[S[id].to]==INF){
                    cnt++;
                }
                sum-=right[S[id].to];
                chmin(right[S[id].to],S[id].cost);
                sum+=right[S[id].to];
            }
            id++;
        }
        if(cnt==N) chmin(miniright[i],sum);
    }
    
    ll ans=INF;
    
    for(int i=0;i+K+1<1000000;i++){
        chmin(ans,minileft[i]+miniright[i+K+1]);
    }
    
    if(ans>=INF) ans=-1;
    
    cout<<ans<<endl;
}