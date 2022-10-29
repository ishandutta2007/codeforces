#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n;
char s[200000];

int main()
{
    scanf("%s",s+1),n=strlen(s+1);
    int a=0,b=0,c=0,i=1;
    for(; i<=n && s[i]=='a'; ++a,++i);
    if(!a) return puts("NO"),0;
    for(; i<=n && s[i]=='b'; ++b,++i);
    if(!b) return puts("NO"),0;
    for(; i<=n && s[i]=='c'; ++c,++i);
    if(i<=n || c!=a && c!=b) return puts("NO"),0;
    puts("YES");
    return 0;
}