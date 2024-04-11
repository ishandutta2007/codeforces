#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

struct edge{
    ll a;
    ll b;
    ll c;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> X(N),Y(N);
    for(int i=0;i<N;i++) cin>>X[i]>>Y[i];
    
    set<pair<pair<ll,ll>,ll>> SE;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ll a=Y[i]-Y[j],b=-(X[i]-X[j]);
            if(a<0){
                a*=-1;
                b*=-1;
            }else if(a==0){
                b=abs(b);
            }
            
            ll g=gcd(abs(a),abs(b));
            a/=g;
            b/=g;
            
            ll c=-a*X[i]-b*Y[i];
            
            SE.insert({{a,b},c});
        }
    }
    
    vector<edge> T;
    
    for(pair<pair<ll,ll>,ll> it:SE){
        T.push_back({it.first.first,it.first.second,it.second});
    }
    
    ll ans=ll(T.size())*ll((T.size()-1))/2;
    
    /*for(int i=0;i<T.size();i++){
        cout<<T[i].a<<" "<<T[i].b<<" "<<T[i].c<<endl;
    }*/
    
    for(ll i=0;i<T.size();){
        ll j=i;
        while(j<T.size()&&T[i].a==T[j].a&&T[i].b==T[j].b) j++;
        ans-=(j-i)*(j-i-1)/2;
        i=j;
    }
    
    cout<<ans<<endl;
}