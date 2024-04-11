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

int t,n;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int ans=0,num=0;
        int j=0;
        while(j<n&&s[j]=='P')j++;
        FOR(i,j,n){
            if(s[i]=='A'){
                chmax(ans,num);
                num=0;
            }else num++;
        }
        cout<<max(ans,num)<<endl;
    }
}