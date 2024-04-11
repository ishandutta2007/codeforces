#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<62;
typedef pair<pair<ll,ll>,pair<ll,ll>> P;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K,A,B;cin>>N>>K>>A>>B;
    vector<ll> S(K);
    for(int i=0;i<K;i++){
        cin>>S[i];
        S[i]--;
    }
    sort(all(S));
    
    set<P> SE;
    for(int i=0;i<K;i++){
        auto it=SE.lower_bound({{S[i],S[i]+1},{0,0}});
        if(it==SE.end()||(*it).fi.fi!=S[i]){
            SE.insert({{S[i],S[i]+1},{B,1}});
        }else{
            P b=(*it);
            SE.erase(b);
            b.se.fi+=B;
            b.se.se++;
            SE.insert(b);
        }
    }
                  
    for(int i=0;i<N;i++){
        set<P> to;
        for(auto a:SE){
            if(a.fi.fi%(1LL<<(i+1))){
                auto it=SE.lower_bound({{a.fi.fi-(1LL<<i),a.fi.fi},{0,0}});
                if((*it).fi.fi==a.fi.fi-(1LL<<i)) continue;
                pair<ll,ll> mi={INF,INF};
                chmin(mi,{a.se.fi+A,a.se.se});
                chmin(mi,{B*(1LL<<(i+1))*a.se.se,a.se.se});
                
                to.insert({{a.fi.fi-(1LL<<i),a.fi.se},mi});
            }else{
                auto it=SE.lower_bound({{a.fi.se,a.fi.se+(1LL<<i)},{0,0}});
                pair<ll,ll> mi={INF,INF};
                if(it==SE.end()||(*it).fi.fi!=a.fi.se){
                    chmin(mi,{a.se.fi+A,a.se.se});
                    chmin(mi,{B*(1LL<<(i+1))*a.se.se,a.se.se});
                }else{
                    P b=(*it);
                    chmin(mi,{a.se.fi+b.se.fi,a.se.se+b.se.se});
                    chmin(mi,{B*(1LL<<(i+1))*(a.se.se+b.se.se),a.se.se+b.se.se});
                }
                
                to.insert({{a.fi.fi,a.fi.se+(1LL<<i)},mi});
            }
        }
        SE=to;
    }
    
    cout<<(*(SE.begin())).se.fi<<endl;
}