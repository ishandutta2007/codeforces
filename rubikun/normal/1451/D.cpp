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
const int mod=1000000007,MAX=200005,INF=1<<30;

ll f(ll rem,ll K){
    ll x=sqrt(rem);
    x++;
    x=x/K*K;
    x+=K;
    
    while(x>=0){
        if(x*x<=rem) return x/K;
        x-=K;
    }
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll D,K;cin>>D>>K;
        vector<ll> A={INF};
        for(ll i=0;i<=D;i+=K){
            ll a=f(D*D-i*i,K);
            A.push_back(a);
        }
        
        while(A.back()==0) A.pop_back();
        
        A.push_back(-INF);
        
        bool ans=true;
        
        int now=0;
        while(1){
            if(now+1<A[now+2]) now++;
            else{
                ll a=A[now+1]-now-1,b=0;
                while(now<A[now+b+2]){
                    b++;
                }
                if(a%2==0&&b%2==0) ans=false;
                break;
            }
        }
        
        if(!ans) cout<<"Ashish\n";
        else cout<<"Utkarsh\n";
    }
}