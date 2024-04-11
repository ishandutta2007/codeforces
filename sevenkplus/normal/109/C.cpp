#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
int n,f[N],s[N];set<int> A;ll S=0;
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)f[i]=i;
    for(int i=1;i<=9;i++)
        for(int k=0;k<(1<<i);k++)
        {
            int x=0;
            for(int j=0;j<i;j++)
                if((k>>j)&1)x=x*10+4;else x=x*10+7;
            A.insert(x);
        }
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(A.find(z)==A.end())f[fa(x-1)]=fa(y-1);
    }
    for(int i=0;i<n;i++)s[fa(i)]++;
    for(int i=0;i<n;i++)s[i]=s[fa(i)];
    for(int i=0;i<n;i++)
    {
        int x=n-s[i];
        S+=(ll)x*(x-1);
    }
    cout<<S<<endl;
    return 0;
}