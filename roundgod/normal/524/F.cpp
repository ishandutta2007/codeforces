#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int r[MAXN+1],sum[MAXN];
int sa[MAXN],rk[MAXN],oldrk[MAXN*2],id[MAXN],px[MAXN],c[MAXN];
string S;
bool cmp(int x,int y,int w)
{
    return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
}
void construct_sa(string S) 
{
    int n=S.length();
    int m=130;
    int i,p,w;
    for(i=1;i<=n;i++) c[i]=0;
    for(i=1;i<=n;i++) ++c[rk[i]=S[i-1]];
    for(i=1;i<=m;i++) c[i]+=c[i-1];
    for(i=n;i>=1;i--) sa[c[rk[i]]--]=i;
    for(w=1;;w<<=1,m=p) {
        for(p=0,i=n;i>n-w;i--) id[++p]=i;
        for(i=1;i<=n;i++) if(sa[i]>w) id[++p]=sa[i]-w;
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++) ++c[px[i]=rk[id[i]]];
        for(i=1;i<=m;i++) c[i]+=c[i-1];
        for(i=n;i>=1;i--) sa[c[px[i]]--]=id[i];
        memcpy(oldrk,rk,sizeof(rk));
        for(p=0,i=1;i<=n;i++)
            rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
        if(p==n){
            for(int i=1;i<=n;i++) rk[i-1]=rk[i]-1;;
            for(int i=0;i<n;i++) sa[rk[i]]=i;
            break;
        }
    }
}
int n,deq[MAXN];
int mini[MAXN];
void precompute()
{
    int s=0,t=0;
    for(int i=1;i<=2*n-1;i++)
    {
        while(s<t&&sum[deq[t-1]]>=sum[i]) t--;
        deq[t++]=i;
        if(i>=n)
        {
            mini[i-n+1]=sum[deq[s]];
            if(deq[s]==i-n+1) s++;
        }
    }
}
int main()
{
    cin>>str; 
    string tmp=str; tmp.pop_back();
    n=(int)str.size();
    str+=tmp;
    for(int i=0;i<(int)str.size();i++) 
    {
        if(str[i]=='(') sum[i+1]=sum[i]+1; else sum[i+1]=sum[i]-1;
    }
    precompute();
    construct_sa(str);
    /*for(int i=0;i<2*n-1;i++)
    {
        cout<<"sa["<<i<<"]="<<sa[i]<<" "<<str.substr(sa[i])<<endl;
    }*/
    string ret;
    if(sum[n]>=0) 
    {
        int id=-1;
        for(int i=0;i<2*n-1;i++)
        {
            if(sa[i]>=n) continue;
            if(mini[sa[i]+1]>=sum[sa[i]])
            {
                id=sa[i];
                break;
            }
        }
        assert(id!=-1);
        ret=str.substr(id,n);
        for(int i=0;i<sum[n];i++) ret+=')';
    }
    else if(sum[n]<0)
    {
        int id=-1;
        for(int i=0;i<2*n-1;i++)
        {
            if(sa[i]>=n) continue;
            if(mini[sa[i]+1]-sum[sa[i]]>=sum[n])
            {
                id=sa[i];
                break;
            }
        }
        assert(id!=-1);
        ret=str.substr(id,n);
        tmp="";
        for(int i=0;i<-sum[n];i++) tmp+='(';
        ret=tmp+ret;
    }
    cout<<ret<<endl;
}