#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int u[201000],v[201000];
main(){
    int n,m,i,tmp,ans = 0,mxu = -1,mxv = -1;
    scanf("%d",&n);
    while(n--){
            scanf("%d",&tmp);
            mp[tmp]++;
    }
    scanf("%d",&m);
    for(i = 0 ; i < m ; i++)
        scanf("%d",u+i);
    for(i = 0 ; i < m ; i++){
        scanf("%d",v+i);
        if(mp[u[i]] == mxu && mxv < mp[v[i]]) mxv = mp[v[i]],ans = i;
        else if(mp[u[i]] > mxu) mxu = mp[u[i]],mxv=mp[v[i]],ans = i;
    }
    printf("%d",ans+1);
}