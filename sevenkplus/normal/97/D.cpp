#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
int n,m,k;char s[100010];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    bitset<22500> a,b,e,c;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            (s[j]=='#'?b:a).set(i*m+j),
            (s[j]=='E'?e.set(i*m+j):0);
    }
    scanf("%s",s);c=a;
    for(int i=0;i<k;i++)
    {
        if(c==e){printf("%d\n",i);return 0;}
        if(s[i]=='U')c=((c>>m)&a)|(c&(b<<m));else
        if(s[i]=='L')c=((c>>1)&a)|(c&(b<<1));else
        if(s[i]=='D')c=((c<<m)&a)|(c&(b>>m));else
        if(s[i]=='R')c=((c<<1)&a)|(c&(b>>1));
    }
    printf("%d\n",c==e?k:-1);
    return 0;
}