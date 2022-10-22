#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
signed main(){
    int N;
    cin>>N;
    int ans=1,n=1;
    for(int i=1;i<=N;i++)ans=ans*i%mod;
    for(int i=1;i<N;i++)n=n*2%mod;
    cout<<(ans-n+mod)%mod<<endl;
}