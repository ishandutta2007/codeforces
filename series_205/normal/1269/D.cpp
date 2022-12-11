#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,a,num[2];

int main(){
    cin>>n;
    rep(i,n){
        cin>>a;
        num[i%2]+=a/2;
        num[(i+1)%2]+=a/2+a%2;
    }
    cout<<min(num[0],num[1])<<endl;
}