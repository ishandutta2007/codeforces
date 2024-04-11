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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> x(N),t(N);
        for(int i=0;i<N;i++){
            cin>>x[i];
            x[i]*=2;
        }
        for(int i=0;i<N;i++){
            cin>>t[i];
            t[i]*=2;
        }
        ll left=-1,right=5e8;
        ll ans=-1;
        while(right-left>1){
            ll mid=(left+right)/2;
            ll l=-INF,r=INF;
            for(int i=0;i<N;i++){
                if(t[i]>mid){
                    l=INF;
                    r=-INF;
                }else{
                    chmax(l,x[i]-(mid-t[i]));
                    chmin(r,x[i]+(mid-t[i]));
                }
            }
            if(l<=r){
                right=mid;
                ans=l;
            }else{
                left=mid;
            }
        }
        
        cout<<fixed<<setprecision(25)<<(double)(ans)/2<<"\n";
    }
}