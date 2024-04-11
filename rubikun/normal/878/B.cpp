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
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K,M;cin>>N>>K>>M;
    vector<pair<int,ll>> FR,BA;
    deque<pair<int,ll>> deq;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        if(si(deq)&&deq.back().fi==x){
            deq.back().se++;
            if(deq.back().se==K) deq.pop_back();
        }else{
            deq.push_back(mp(x,1LL));
        }
    }
    
    if(M==1){
        ll ans=0;
        for(auto a:deq) ans+=a.se;
        cout<<ans<<endl;
        return 0;
    }
    
    if(si(deq)==0){
        cout<<0<<endl;
        return 0;
    }
    if(si(deq)==1){
        ll ans=deq.back().se*M%K;
        cout<<ans<<endl;
        return 0;
    }
    if(deq.front().fi!=deq.back().fi){
        ll sum=0;
        for(auto a:deq) sum+=a.se;
        cout<<sum*M<<endl;
        return 0;
    }
    
    while(1){
        if(si(deq)==0){
            ll ans=0;
            while(si(FR)){
                if(FR.back().fi!=BA.back().fi){
                    for(auto a:FR) ans+=a.se;
                    for(auto a:BA) ans+=a.se;
                    cout<<ans<<endl;
                    return 0;
                }else{
                    ll x=FR.back().se,y=BA.back().se;
                    if((x+y)%K==0){
                        FR.pop_back();
                        BA.pop_back();
                    }else{
                        ans+=(x+y)%K;
                        FR.pop_back();
                        BA.pop_back();
                        for(auto a:FR) ans+=a.se;
                        for(auto a:BA) ans+=a.se;
                        cout<<ans<<endl;
                        return 0;
                    }
                }
            }
            cout<<0<<endl;
            return 0;
        }
        if(si(deq)==1){
            ll x=deq.back().se;
            if((x*M)%K==0){
                deq.pop_back();
                continue;
            }else{
                ll ans=0;
                ans+=(x*M)%K;
                for(auto a:FR) ans+=a.se;
                for(auto a:BA) ans+=a.se;
                cout<<ans<<endl;
                return 0;
            }
        }
        if(deq.front().fi!=deq.back().fi){
            ll ans=0;
            for(auto a:deq) ans+=a.se*M;
            for(auto a:FR) ans+=a.se;
            for(auto a:BA) ans+=a.se;
            cout<<ans<<endl;
            return 0;
        }
        ll x=deq.front().se,y=deq.back().se;
        if((x+y)%K){
            ll ans=0;
            FR.push_back(deq.front());
            BA.push_back(deq.back());
            ans+=((x+y)%K)*(M-1);
            deq.pop_front();
            deq.pop_back();
            for(auto a:deq) ans+=a.se*M;
            for(auto a:FR) ans+=a.se;
            for(auto a:BA) ans+=a.se;
            cout<<ans<<endl;
            return 0;
        }else{
            FR.push_back(deq.front());
            BA.push_back(deq.back());
            deq.pop_front();
            deq.pop_back();
        }
    }
}