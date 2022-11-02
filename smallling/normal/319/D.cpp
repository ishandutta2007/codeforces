#include<cstdio>
#include<cstring>

using namespace std;

char s[100010];
int len,nowlen;

int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len/2;i++)
    {
        nowlen=0;
        for(int j=1;j<=len-i;j++)
        {
            if(s[j]==s[j+i])nowlen++;
            else nowlen=0;
            if(nowlen==i)
            {
                for(int k=j+1;k<=len-i;k++)
                    s[k]=s[k+i];
                len-=i;
                i--;
                break;
            }
        }
    }
    s[len+1]=0;
    puts(s+1);
}