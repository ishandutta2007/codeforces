#include<cstdio>
#include<map>
#include<cstring>

using namespace std;

int val[26],len;
long long Ans,sum[100010];
map<long long,int>ans[26];
char s[100010];

int main()
{
    for(int i=0;i<26;i++)
        scanf("%d",&val[i]);
    scanf("%s",s);
    len=strlen(s);
    for(int i=1;i<=len;i++)
        sum[i]=sum[i-1]+val[s[i-1]-'a'],Ans+=ans[s[i-1]-'a'][sum[i-1]],ans[s[i-1]-'a'][sum[i]]++;
    printf("%I64d",Ans);
}