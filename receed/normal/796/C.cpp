#include <bits/stdc++.h>

using namespace std;
int n,u,v;
vector<int>a(300001);
vector<vector<int> >g(300001);


int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int m=-1000000001,m2=-1000000001,cm=0,cm2=0;
    for(int i=1;i<=n;i++){
        if(a[i]>m){
            m2=m;
            m=a[i];
            cm2=cm;
            cm=1;
        }
        else if(a[i]==m)
            cm++;
        else if(a[i]>m2){
            m2=a[i];
            cm2=1;
        }
        else if(a[i]==m2)
            cm2++;
    }
    int ans=2000000000,c,t,t2;
    for(int i=1;i<=n;i++){
        c=a[i];
        t=cm;
        t2=cm2;
        if(a[i]==m) t--;
        if(a[i]==m2) t2--;
        for(int j=0;j<g[i].size();j++){
            c=max(c,a[g[i][j]]+1);
            if(a[g[i][j]]==m) t--;
            if(a[g[i][j]]==m2) t2--;
        }
        if(t>0) c=max(c,m+2);
        if(t2>0) c=max(c,m2+2);
        ans=min(ans,c);
    }
    cout<<ans;
    return 0;
}