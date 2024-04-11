#include<bits/stdc++.h>
using namespace std;
int main()
{int n,t,k,d;
cin>>n>>t>>k>>d;
n=(n+k-1)/k;//(T-d)/t+T/t>=n
//cout<<n*t<<" "<<d+t<<endl;
if(n*t<=d+t) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}