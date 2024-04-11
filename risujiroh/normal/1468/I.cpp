#include "bits/stdc++.h"
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a,const T &b) { if(a<b) { a=b;return true;} return false;}
template<class T>bool chmin(T &a,const T &b) { if(b<a) { a=b;return true;} return false;}
#define mp make_pair
#define fi first
#define se second
#define si(x) int(x.size())
#define all(x) (x).begin(),(x).end()
const ll INF=1LL<<60;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(nullptr)->sync_with_stdio(false);
    
    ll N;cin>>N;
    ll dx1,dy1,dx2,dy2;cin>>dx1>>dy1>>dx2>>dy2;
    
    if(dx1==0&&dx2==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    if(dy1==0&&dy2==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    if(dx1==0&&dy1==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    if(dx2==0&&dy2==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    ll gx=abs(gcd(dx1,dx2)),gy=abs(gcd(dy1,dy2));
    
    dx1/=gx;
    dx2/=gx;
    dy1/=gy;
    dy2/=gy;
    
    ll D=abs(dx1*dy2-dx2*dy1);
    
    if(D*gx*gy!=N){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    
    for(int i=0;i<gx;i++){
        for(int j=0;j<gy*D;j++){
            cout<<i<<" "<<j<<"\n";
        }
    }
}