#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
ll t;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){
    if((long double)a/gcd(a,b)>(long double)(t+1)/b) return t+2;
    return a/gcd(a,b)*b;
}
int main()
{
    ll w,b;cin>>t>>w>>b;
    ll res=((t+1)/lcm(w,b)*min(w,b))+min((t+1)%lcm(w,b),min(w,b))-1;
    if(res>0){
        ll tmp=gcd(res,t);
        cout<<(res/tmp)<<"/"<<(t/tmp)<<endl;
    }else{
        cout<<"0/1"<<endl;
    }
    return 0;
}