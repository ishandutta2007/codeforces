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
const int mod=1000000007,MAX=1005;
const ll INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,L,R,K;cin>>N>>L>>R>>K;
    ll X,Y;
    if(L<=R) X=R-L+1;
    else X=N-(L-R-1);
    Y=N-X;
    
    //cout<<X<<" "<<Y<<endl;
    
    if(N<=3000){
        int ans=-1;
        
        for(int i=0;i<=X;i++){
            for(int j=0;j<=Y;j++){
                ll sum=N+i+j,s=K/sum,t=K%sum;
                if(t==X+i) chmax(ans,i+j);
                else if(i>=1&&t==X+i-1) chmax(ans,i+j);
                else if(t==0&&X==N) chmax(ans,i+j);
            }
        }
        
        cout<<ans<<endl;
    }else{
        ll ans=-1;
        
        if(X<=K&&K<=2*X){
            if(K==2*X) chmax(ans,N);
            else chmax(ans,K-X+1+Y);
        }
        
        for(ll z=0;z<2;z++){
            for(int q=1;q<=K/N;q++){
                ll l=K/(q+1),r;
                if(K%q==0) r=K/q-1;
                else r=K/q;
                
                if(l>r) continue;
                
                ll reml=K-q*l,remr=K-q*r;
                
                if(remr>2*X) continue;
                if(reml<X) continue;
                
                //cout<<reml<<" "<<remr<<endl;
                
                {
                    ll mini=X;
                    chmax(mini,remr);
                    if(mini%q!=remr%q) mini=remr+(mini-remr+q-1)/q*q;
                    ll b=(K-mini)/q-N-(mini-X);
                    if(0<=b&&b<=Y){
                        if(mini<=2*X) chmax(ans,mini-X+b);
                    }else if(b>Y){
                        ll need=(b-Y+q)/(q+1);
                        mini+=need*q;
                        ll a=mini-X,b=(K-mini)/q-N-a;
                        if(0<=a&&a<=X&&0<=b&&b<=Y) chmax(ans,a+b);
                    }
                }
            }
            K++;
        }
        
        cout<<ans<<endl;
    }
}