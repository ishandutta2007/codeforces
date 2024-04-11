#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;



#define MOD 1000000007

int n,k;
int a[15];
long long ans=0;


void input();
void solve();
//void BATRAK(int pos);
//int check();

int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d%d",&n,&k);
    }


void solve()
    {
    //BATRAK(1);
    int i;
    if(k==1)ans=1;
    if(k==2)ans=2;
    if(k==3)ans=9;
    if(k==4)ans=64;
    if(k==5)ans=625;
    if(k==6)ans=7776;
    if(k==7)ans=117649;
    if(k==8)ans=2097152;
    for(i=1;i<=n-k;i++)
        {
        ans=(ans*(n-k))%MOD;
        //printf("%I64d\n",ans);
        }
    printf("%I64d\n",ans);
    }

/*
void BATRAK(int pos)
    {
    int i;
    if(pos==k+1){ans+=check();return ;}
    for(i=1;i<=k;i++)
        {
        a[pos]=i;
        BATRAK(pos+1);
        a[pos]=0;
        }
    }


int check()
    {
    int i;
    int br=0;
    int p;
    for(i=1;i<=k;i++)
        {
        p=i;
        br=0;
        while(1)
            {
            br++;
            if(br==10)return 0;
            p=a[p];
            if(p==1)break;
            }
        }
    //for(i=1;i<=k;i++)
        //{
        //printf("%d ",a[i]);
        //}
    //printf("\n");
    return 1;
    }
*/