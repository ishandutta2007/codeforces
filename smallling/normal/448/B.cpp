#include<cstdio>
#include<cstring>

using namespace std;

char s1[1001],s2[1001];
int len1,len2,sum[100001];

int main()
{
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    if(len1==len2)
    {
        for(int i=1;i<=len1;i++)
            sum[s1[i]]++,sum[s2[i]]--;
        for(int i=(int)('a');i<=(int)('z');i++)
            if(sum[i])
            {
                puts("need tree");
                return 0;
            }
        puts("array");
        return 0;
    }
    if(len1<len2)
    {
        puts("need tree");
        return 0;
    }
    int now=1,bo=1;
    for(int i=1;i<=len2;i++)
    {
        for(;now<=len1&&s1[now]!=s2[i];now++);
        if(now>len1)
        {
            bo=0;
            break;
        }
        now++;
    }
    if(bo)
    {
        puts("automaton");
        return 0;
    }
    for(int i=1;i<=len1;i++)
        sum[s1[i]]++;
    for(int i=1;i<=len2;i++)
        sum[s2[i]]--;
    for(int i=(int)('a');i<=(int)('z');i++)
        if(sum[i]<0)
        {
            puts("need tree");
            return 0;
        }
    puts("both");
}