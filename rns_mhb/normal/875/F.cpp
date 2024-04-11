#include<bits/stdc++.h>
using namespace std;
int main() {
ios::sync_with_stdio(false);cin.tie(0);
int n,m;
cin>>n>> m;
vector<tuple<int,int,int>>e(m);
for(int i=0;i<m;i++)cin>>get<1>(e[i])>>get<2>(e[i])>>get<0>(e[i]);
sort(e.begin(),e.end());
vector<int>f(n+1),b(n+1,0);
function<int(int)>find_rt=[&](int x){return f[x]==x?x:f[x]=find_rt(f[x]);};
for(int i=1;i<=n;i++)f[i]=i;
long long ans=0;
for(int i=m-1;i>=0;i--) {
int x = find_rt(get<1>(e[i])),y=find_rt(get<2>(e[i]));
if(b[x]&&b[y]) continue;
if(x==y)b[x] = 1;
else f[x]=y,b[y]|=b[x];
ans+=get<0>(e[i]);
}
cout<<ans<<endl;
}