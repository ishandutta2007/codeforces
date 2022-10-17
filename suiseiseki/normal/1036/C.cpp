#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
ll f[20][5];
int a[20];
ll dfs(int pos,int st,bool limit){
    if(pos==-1){
        return 1;
    }
    if(!limit&&f[pos][st]!=-1){
        return f[pos][st];
    }
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        if(i==0){
            ans+=dfs(pos-1,st,limit&&a[pos]==i);
        }
        else if(st<3){
            ans+=dfs(pos-1,st+1,limit&&a[pos]==i);
        }
    }
    if(!limit){
        return f[pos][st]=ans;
    }
    return ans;
}
int len;
ll work(ll x){
    len=0;
    while(x>0){
        a[len++]=x%10;
        x/=10;
    }
    memset(f,-1,sizeof f);
    return dfs(len-1,0,1);
}
int main(){
    int t;
    scanf("%d",&t);
    ll left,right;
    while(t--){
        cin>>left>>right;
        cout<<work(right)-work(left-1)<<endl;
    }
    return 0;
}