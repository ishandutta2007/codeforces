#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char num[1000010];
int flag[10];

int main()
{
    int i,len,tmp;
    while(~scanf("%s",num))
    {
        len=strlen(num);
        memset(flag,0,sizeof(flag));
        tmp=0;
        for(i=0;i<len;i++)
        {
            if(num[i]=='0') flag[0]++;
            else if(num[i]=='1'&&!flag[1]) flag[1]=1;
            else if(num[i]=='6'&&!flag[6]) flag[6]=1;
            else if(num[i]=='8'&&!flag[8]) flag[8]=1;
            else if(num[i]=='9'&&!flag[9]) flag[9]=1;
            else
            {
                printf("%c",num[i]);
                tmp=tmp*10+num[i]-'0';
                tmp%=7;
            }
        }
        if(tmp==0) printf("1869");
        else if(tmp==1) printf("6198");
        else if(tmp==2) printf("1896");
        else if(tmp==3) printf("6918");
        else if(tmp==4) printf("1986");
        else if(tmp==5) printf("1968");
        else if(tmp==6) printf("1698");
        for(i=1;i<=flag[0];i++) printf("0");
        printf("\n");
    }
    return 0;
}