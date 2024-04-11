#include<bits/stdc++.h>
using namespace std;
long long n,c[200090],l[200009],r[200009],t[200009],f[200009],F[200009],k;
vector<long long> v[200009];
void dfs(long long x)
{f[x]=1;
t[x]=c[x];
long long p=-1,q=-1;
for (long long i=0; i<v[x].size(); i++)
if (f[v[x][i]]==0) {dfs(v[x][i]);
if (p==-1) p=i;  q=i;
t[x]+=t[v[x][i]];
}
if (p==-1) {l[x]=k; r[x]=k; k++; return;}
l[x]=l[v[x][p]];
r[x]=r[v[x][q]];
}
main()
{cin>>n;
if (n==1) {cout<<"Impossible"<<endl; return 0;}
for (long long i=1; i<=n; i++)
cin>>c[i];
for (long long i=0; i<n-1; i++)
{long long a,b; cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);}
dfs(1);long long mm=0;
for (int i=2; i<=n; i++)
if (v[i].size()==1) mm++;
if (mm==1) {cout<<"Impossible"<<endl; return 0;}
pair<long long ,long long> H[200009],T[200009];
long long Y[200009];
for (long long i=1; i<=n; i++)
{H[i].first=l[i];
H[i].second=i;
T[i].first=r[i];
T[i].second=i;}
sort(T+1,T+n+1);
Y[T[1].first]=t[T[1].second];
F[T[1].first]=1;
for (long long i=2; i<=n; i++)
{//cout<<T[i].first<<" "<<t[T[i].second]<<endl;
Y[T[i].first]=max(Y[T[i-1].first],t[T[i].second]);
F[T[i].first]=1;
}long long ans=-1000000000000000;
for (long long i=0; i<=n; i++)
{if (F[i]==0) Y[i]=Y[i-1];
//cout<<Y[i]<<" ";
}
for (long long i=1; i<=n; i++)
if (H[i].first>0) ans=max(ans,t[H[i].second]+Y[H[i].first-1]);
cout<<ans<<endl;


}