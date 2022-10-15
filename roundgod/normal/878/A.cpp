#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int cal[10];
char c;
bool used[4];
int main()
{
    scanf("%d",&n);
    getchar();
    memset(cal,0,sizeof(0));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%c %d",&c,&x);
        getchar();
        for(int i=0;i<10;i++)
        {
            int d=x&1;
            if(c=='|')
                if(d==1)
                    cal[i]=1;
            if(c=='&')
                if(d==0)
                    cal[i]=2;
            if(c=='^')
                if(d==1)
                {
                    if(cal[i]==0) cal[i]=3;
                    else if(cal[i]==1) cal[i]=2;
                    else if(cal[i]==2) cal[i]=1;
                    else if(cal[i]==3) cal[i]=0;
                }
            x=x>>1;
        }
    }
    memset(used,false,sizeof(used));
    int cnt=0;
    for(int i=0;i<10;i++)
        if(!used[cal[i]]&&cal[i]!=0) {cnt++; used[cal[i]]=true;}
    printf("%d\n",cnt);
    if(used[1])
    {
        int x=0,t=1;
        for(int i=0;i<10;i++)
        {
            if(cal[i]==1) x+=t;
            t*=2;
        }
        printf("| %d\n",x);
    }
    if(used[2])
    {
        int x=0,t=1;
        for(int i=0;i<10;i++)
        {
            if(cal[i]!=2) x+=t;
            t*=2;
        }
        printf("& %d\n",x);
    }
    if(used[3])
    {
        int x=0,t=1;
        for(int i=0;i<10;i++)
        {
            if(cal[i]==3) x+=t;
            t*=2;
        }
        printf("^ %d\n",x);
    }
    return 0;
}