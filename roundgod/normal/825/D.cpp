#include<bits/stdc++.h>
#define MAXN 1000030
using namespace std;
char a[MAXN],b[MAXN];
int na[26],nb[26],x=0;
int pos[MAXN];
bool C(int p)
{
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        cnt+=max(0,nb[i]*p-na[i]);
        if(cnt>x) return false;
    }
    return true;
}
int main()
{
    scanf("%s",a);
    scanf("%s",b);
    int stra=strlen(a),strb=strlen(b);
    for(int i=0;i<stra;i++)
    {
        if(a[i]=='?')
           {
             pos[x]=i;
             x++;
           }
        else
        {
            na[a[i]-97]++;
        }
    }
    for(int i=0;i<strb;i++)
    {
        nb[b[i]-97]++;
    }
    int lb=0,ub=stra/strb+1;
    while(ub-lb>1)
    {
        int mid=(lb+ub)/2;
        if(C(mid)) lb=mid;
        else ub=mid;
    }
    int s=0;
    for(int i=0;i<26;i++)
    {
        nb[i]=max(0,nb[i]*lb-na[i]);
        s+=nb[i];
    }
    int p=x,k=0;
    assert(p>=s);
    for(int i=0;i<26;i++)
    {
       for(int j=0;j<nb[i];j++)
       {
           a[pos[k]]=i+97;
           k++;
       }
    }
    for(int i=k;i<p;i++)
        a[pos[i]]=97;
    printf("%s",a);
    return 0;
}