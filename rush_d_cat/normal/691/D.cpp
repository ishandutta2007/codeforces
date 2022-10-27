#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const ll maxn=1000000+10;
vector<ll> vec[1000000+10],vec1,vec2;
ll a[maxn],next[maxn],used[maxn];
void dfs(ll x){
    if(used[x]) return;
    used[x]=1;
    vec1.push_back(x);
    vec2.push_back(a[x]);
    int sz=vec[x].size();
    for(int i=0;i<sz;i++){
        dfs(vec[x][i]);
    }
    return;
}
int main(){
    ll n,m;scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=m;i++){
        ll x,y;scanf("%I64d%I64d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        dfs(i);
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        int sz=vec2.size();
        for(int j=0;j<sz;j++){
            a[vec1[j]]=vec2[sz-j-1];
        }
        vec1.clear();vec2.clear();
    }
    for(int i=1;i<=n;i++){
        printf("%I64d",a[i]);
        if(i==n) printf("\n");
        else printf(" ");
    }
    return 0;
}