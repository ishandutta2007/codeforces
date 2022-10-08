#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll k,b,n,t;
int main()
{
    cin>>k>>b>>n>>t;
    int S=n;ll w=1;
    while(w<=t)(w*=k)+=b,S--;S++;
    cout<<max(S,0)<<endl;
    return 0;
}