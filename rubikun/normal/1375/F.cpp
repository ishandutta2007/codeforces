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
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    ll a,b,c;cin>>a>>b>>c;
    cout<<"First"<<endl;
    
    vector<ll> X={a,b,c};
    sort(all(X));
    
    ll x=2*X[2]-X[1]-X[0];
    cout<<x<<endl;
    ll s;cin>>s;
    
    int ma=0;
    if(a>b&&a>c) ma=1;
    if(b>a&&b>c) ma=2;
    if(c>a&&c>b) ma=3;
    
    if(s==1) a+=x;
    if(s==2) b+=x;
    if(s==3) c+=x;
    
    if(s!=ma){
        X={a,b,c};
        sort(all(X));
        cout<<X[1]-X[0]<<endl;
        cin>>s;
        return 0;
    }else{
        ll y=6*X[2]-3*X[1]-3*X[0];
        cout<<y<<endl;
        
        cin>>s;
        if(s==1) a+=y;
        if(s==2) b+=y;
        if(s==3) c+=y;
        
        X={a,b,c};
        sort(all(X));
        
        cout<<X[1]-X[0]<<endl;
        cin>>s;
        return 0;
    }
}