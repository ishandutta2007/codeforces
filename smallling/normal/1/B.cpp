#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int m,n;

int f[100001],t;

char s[1001];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int l=strlen(s+1);
        int o=0;
        for(int i=2;i<=l;i++)
            if(s[i]<='9'&&s[i]>='0'&&s[i-1]>='A'&&s[i-1]<='Z')
                o++;
        if(o==1)
        {
            int sum=0;
            int i;
            for(i=1;i<=l;i++)
            {
                if(s[i]<='9'&&s[i]>='0')break;
                sum=sum*26+(s[i]-'A'+1);
            }
            printf("R");
            for(int j=i;j<=l;j++)
                printf("%c",s[j]);
            printf("C%d\n",sum);
        }
        else 
        {
            int sum=0;
            int i;
            for(i=2;i<=l;i++)
            {
                if (s[i]=='C')break;
                sum=sum*10+s[i]-'0';
            }
            int p=0;
            for(int j=i+1;j<=l;j++)
                p=p*10+s[j]-'0'; 
            int tot=0;
            int now=26;
            int lo=0;
            while(p)
                if(p%26)f[++lo]=p%26,p/=26;
                else f[++lo]=26,p=p/26-1;
            for(int i=lo;i;i--)
                printf("%c",f[i]+'A'-1);
            printf("%d\n",sum);
        }
    }              
   return 0;
}