#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
char s[N];int n,a[30],f[N],m,S;bool v[30][30];
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        char t[5];scanf("%s",t);
        v[t[0]-'a'][t[1]-'a']=1,
        v[t[1]-'a'][t[0]-'a']=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
            if(!v[j][s[i]-'a'])f[i]=max(f[i],f[a[j]]+1);
        a[s[i]-'a']=i;S=max(S,f[i]);
    }
    printf("%d\n",n-S);
    return 0;
}