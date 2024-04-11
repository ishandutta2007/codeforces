#include<stdio.h>
#include<iostream>
using namespace std;


int n;
char num[17][8];
int bull[17],cow[17];
char tc[8],ans[8];

void input()
    {
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        scanf("%s%d%d",&num[i],&bull[i],&cow[i]);
        }
    }
void solve()
    {
    int i,j,k,sum=0;
    for(char a='0';a<='9';a++)
        {
        for(char b='0';b<='9';b++)
            {
            for(char c='0';c<='9';c++)
                {
                for(char d='0';d<='9';d++)
                    {
                    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
                        {
                        tc[0]=a;
                        tc[1]=b;
                        tc[2]=c;
                        tc[3]=d;
                        int l=0;
                        for(i=1;i<=n;i++)
                            {
                            int bulls=0,cows=0;
                            for(j=0;j<4;j++)
                            for(k=0;k<4;k++)
                            if(tc[j]==num[i][k])
                                {
                                if(j==k) bulls++;
                                else cows++;
                                }
                            if(bulls!=bull[i]||cows!=cow[i]) {
                                l=1;
                                break;
                                }
                            }
                        if(!l)
                            {
                            sum++;
                            for(i=0;i<4;i++) ans[i]=tc[i];
                            }
                        }
                    }
                }
            }
        }
    if(sum==0) printf("Incorrect data\n");
    else if(sum==1) printf("%s\n",ans);
    else printf("Need more data\n");
    }

int main()
    {
    input();
    solve();
    return 0;
    }