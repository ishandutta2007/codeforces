#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const ll MAX=2000000+2;
ll a[1000+2];
int mark[MAX];
int main(){
    ll res=0;
    ll ha=0;
    memset(mark,0,sizeof(mark));
    for(ll i=2;i<=MAX;i++) if(!mark[i]) for(ll j=2*i;j<=MAX;j+=i) mark[j]=1;
    mark[2]=0;
    int n;cin>>n;
    if(n==1){
        cin>>res;
        cout<<1<<endl;
        cout<<res<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res+=(a[i]==1);
        if(a[i]!=1&&!mark[a[i]+1]) ha=a[i];
    }
    ll x=0,y=0;
    if(res==0||(res==1&&!ha)){  //2 primes
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!mark[a[i]+a[j]]){
                    x=a[i];y=a[j];
                }
            }
        }
        if(x==0){
            cout<<1<<endl;
            cout<<a[1]<<endl;
        }else{
            cout<<2<<endl;
            cout<<x<<" "<<y<<endl;
        }
        return 0;
    }
    if(ha){
        cout<<res+1<<endl;
        for(int i=1;i<=res;i++) cout<<1<<" ";
        cout<<ha<<endl;
    }else{
        cout<<res<<endl;
        for(int i=1;i<=res-1;i++) cout<<1<<" ";
        cout<<1<<endl;
    }
    return 0;
}