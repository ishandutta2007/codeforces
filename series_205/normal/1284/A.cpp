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

int n,m;
string s[30],t[30];

int main(){
    cin>>n>>m;
    rep(i,n)cin>>s[i];
    rep(i,m)cin>>t[i];
    int q; cin>>q;
    rep(i,q){
        int x;
        cin>>x;
        x--;
        cout<<s[x%n]<<t[x%m]<<endl;
    }
}