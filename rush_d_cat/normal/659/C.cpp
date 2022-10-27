#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
typedef __int64 ll;
ll a[100000+2],n,k;
map<ll,bool> mp;
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        mp[a[i]]=true;
    }
    sort(a+1,a+n+1);
    ll res=0,tmp=1,cnt=0;
    for(int i=1;i<=k;i++){
        if(!mp[i]){
            res+=i;
            if(res>k) break;
            cnt++;
        }
    }
    printf("%I64d\n",cnt);
    res=0;tmp=1;
    for(ll i=1;i<=k;i++){
        if(!mp[i]){
            res+=i;
            if(res>k) break;
            printf("%I64d ",i);
        }
    }
    return 0;
}