#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

/*-------------------------------------------*/

int l[100009],mn,mx,x;
ll n,y;
vector<int> MX,MN;

int main(){
    cin>>n;
    rep(i,n){
        cin>>l[i];
        mn=1e9;
        mx=0;
        bool ok=0;
        rep(j,l[i]){
            cin>>x;
            if(mn<x)ok=1;
            chmax(mx,x);
            chmin(mn,x);
        }
        if(!ok){
            MX.push_back(mx);
            MN.push_back(mn);
        }
    }
    sort(MN.begin(),MN.end());
    sort(MX.begin(),MX.end());
    rep(i,MN.size()){
        y+=upper_bound(MX.begin(),MX.end(),MN[i])-MX.begin();
    }
    cout<<n*n-y<<endl;
}