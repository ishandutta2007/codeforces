#include<cstdio>
#include<cstring>

using namespace std;

int l,a[26],ans;
char s[1001];

int main()
{
    char ch=getchar();
    while(ch!='\n')s[++l]=ch,ch=getchar();
    for(int i=1;i<=l;i++)
        if(s[i]<='z'&&s[i]>='a')ans+=!a[s[i]-'a'],a[s[i]-'a']=1;
    printf("%d",ans);
}