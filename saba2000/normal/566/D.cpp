#include<bits/stdc++.h>
using namespace std;
int p[1000009],s[1000009],N[1000009];
int n,m;
int par(int x)
{
    if(p[x]==x) return x;
    {
    int u=par(p[x]);
    p[x]=u;
    return u;
    }
}
void un(int x, int y)
{
    int a=par(x),b=par(y);
    if(a==b) return;
    if(s[a]<s[b]) {p[a]=b; s[b]+=s[a];}
    else{p[b]=a; s[a]+=s[b];}
}
main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {p[i]=i;
    N[i]=i;}
    while(m--)
    {int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
    if(a==1) un(b,c);
    if(a==3) if(par(b)==par(c)) printf("YES\n");
else printf("NO\n");
    if(a==2)
    {
        for (int i=b+1; i<=c; i++)
        {
            un(i,i-1);
            int x=N[i];
            N[i]=max(N[i],c);
            i=x;
        }
    }
    }
}