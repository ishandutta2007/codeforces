#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef __int64 ll;
map<ll,ll> mp;
int main(){
    int q;cin>>q;
    ll u,v,w;
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==1){
            cin>>u>>v>>w;
            while(u!=v){
                if(u>v){
                    mp[u]+=w;u/=2;
                }
                if(v>u){
                    mp[v]+=w;v/=2;
                }
            }
        }else{
            cin>>u>>v;
            ll res=0;
            while(u!=v){
                if(u>v){
                    res+=mp[u];u/=2;
                }
                if(v>u){
                    res+=mp[v];v/=2;
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}