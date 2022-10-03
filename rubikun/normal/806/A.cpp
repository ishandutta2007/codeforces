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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll x,y,p,q;cin>>x>>y>>p>>q;
        if(p==1&&q==1){
            if(x==y) cout<<0<<"\n";
            else cout<<-1<<"\n";
        }else if(p==0){
            if(x==0) cout<<0<<"\n";
            else cout<<-1<<"\n";
        }else{
            ll lim=max((y-x)/(q-p),x/p);
            for(ll M=lim;;M++){
                ll a=M*p-x,b=M*q-y;
                if(0<=a&&a<=b){
                    cout<<b<<"\n";
                    break;
                }
            }
        }
    }
}