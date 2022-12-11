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
ll ans;
int n,k;
string s[2000];

map<string,int> mp;

int f(char c){
    if(c=='S')return 1;
    if(c=='E')return 2;
    return 3;
}

int main(){
    cin>>n>>k;
    rep(i,n){
        cin>>s[i];
        mp[s[i]]++;
    }
    rep(i,n){
        FOR(j,i+1,n){
            string t;
            t.resize(k);
            rep(l,k){
                if(s[i][l]==s[j][l])t[l]=s[i][l];
                else{
                    int x=f(s[i][l])^f(s[j][l]);
                    if(x==1)t[l]='S';
                    if(x==2)t[l]='E';
                    if(x==3)t[l]='T';
                }
            }
            ans+=mp[t];
        }
    }
    cout<<ans/3<<endl;
}