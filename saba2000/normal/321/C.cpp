#include<bits/stdc++.h>
using namespace std;
int sub[100009],fix[100009];
vector<int> v[100009],l[100009];
int sm=100000000,hm=0;
char ans[1000009];
void fs(int x)
{
    fix[x]=1;
    sub[x]=1;
    for (int i=0; i<v[x].size(); i++)
    {
        if(fix[v[x][i]]==1) continue;
        fs(v[x][i]);
        sub[x]+=sub[v[x][i]];
    }
    fix[x]=0;
}
int fc(int x, int n)
{
    //cout<<x<<" "<<sub[x]<<" "<<n<<endl;
    fix[x]=1;
    for (int i=0; i<v[x].size(); i++)
    {
        if(fix[v[x][i]]==1) continue;
        if(sub[v[x][i]]>n/2) { int u= fc(v[x][i],n); fix[x]=0; return u;}
    }
    fix[x]=0;
    return x;
}
void cnt(int x,char k)
{
    fs(x);
    int C=fc(x,sub[x]);
   fix[C]=1;
   ans[C]=k;
for (int i=0; i<v[C].size(); i++)
        if(fix[v[C][i]]==0) cnt(v[C][i],k+1);

}
main()
{int n;
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cnt(1,'A');
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}