#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



long long t[1000007];
int r[1000007];



long long d(int x);


int ispr(int x);

int main()
    {
    int a,b,c;
    int i,j,k;
    long long ans=0;
    scanf("%d%d%d",&a,&b,&c);
    for(i=1;i<=a;i++)
        {
        for(j=1;j<=b;j++)
            {
            for(k=1;k<=c;k++)
                {
                if(t[i*j*k]!=0)ans+=t[i*j*k];
                else ans+=d(i*j*k);
                ans=ans%1073741824 ;
                }
            }
        }
    cout<<ans<<"\n";
    return 0;
    }


long long d(int x)
    {
    int i;
    int k;
    int br=0;
    int ret=1;
    //printf("%d\n",x);
    if(t[x]!=0)return t[x];
    int sk=1;
    for(i=1;i*i<=x;i++)
        {
        if(x%i==0)
            {
            if(ispr(i)==1)
                {
                k=x;
                br=0;
                if(i!=1)
                    {
                    while(k%i==0)
                        {
                        br++;
                        k=k/i;
                        }
                    ret*=(br+1);
                    }
                else ret=ret*1;
                }
            if(i*i!=x && ispr(x/i)==1)
                {
                k=x;
                br=0;
                while(k%(x/i)==0)
                    {
                    br++;
                    k=k/(x/i);
                    }
                ret*=(br+1);
                }
            }
        }
    t[x]=ret;
    return ret;
    }




int ispr(int x)
    {
    int i;
    if(r[x]==2)return 0;
    if(r[x]==1)return 1;
    for(i=2;i*i<=x;i++)
        {
        if(x%i==0){r[x]=2;return 0;}
        }
    r[x]=1;
    return 1;
    }