#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,pa[60],pc[60][60];int pb[60],L,v[60];ll S,SA,SB,w;int p;
void gg(int x,ll y,ll z)
{
    if(y>p)return;
    if(x==L)
    {
        if(z*(y+w/y)+w<S)
            S=z*(y+w/y)+w,SA=z,SB=y;
        return;
    }
    for(int i=pb[x]-v[x];i>=0;i--)
        gg(x+1,y*pc[x][i],z);
}
void ff(int x,ll y)
{
    if(n/y/y/y<1)return;
    if(x==L)
    {
        p=(int)sqrt((long double)(n/y+1e-8)),w=n/y;
        if(y*(p+w/p)+w<S)gg(0,1,y);return;
    }
    for(int i=pb[x];i>=0;i--)
        v[x]=i,ff(x+1,y*pc[x][i]);
}
int main()
{
    int _;cin>>_;
    while(_--)
    {
        cin>>L;n=1;
        for(int i=0;i<L;i++)
        {
            cin>>pa[i]>>pb[i];pc[i][0]=1;
            for(int j=0;j<pb[i];j++)n*=pa[i],pc[i][j+1]=pc[i][j]*pa[i];
        }
        S=2*n+1,SA=1,SB=1;
        ff(0,1);
        cout<<S*2<<" "<<SA<<" "<<SB<<" "<<n/SA/SB<<endl;
    }
    return 0;
}