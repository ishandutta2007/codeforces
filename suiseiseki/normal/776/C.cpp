#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000000000000ll
int a[100005];
ll sum[100005];
vector<ll> x;
map<ll,int> mp;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    x.push_back(1);
    if(k!=1&&k!=-1){
        while((x[x.size()-1])*k<=Maxn){
            x.push_back((x[x.size()-1])*k);
        }
    }
    if(k==-1){
        x.push_back(-1);
    }
    ll ans=0;
    mp[0]++;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        mp[sum[i]]++;
        for(int j=0;j<(int)x.size();j++){
            if(mp.find(sum[i]-x[j])!=mp.end()){
                ans+=mp[sum[i]-x[j]];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}