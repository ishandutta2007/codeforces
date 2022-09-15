#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 300010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef int i64;
//typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,cnt,sm,fg;

/*
int ara[si],cnt_p=1,pr[si];

void sieve()
{
    int num=si-5,i,j,root;
    root=sqrt(num);
    pr[cnt_p++]=2;
    ara[1]=1;
    for(i=3;i<=num;i=i+2)
    {
        if(ara[i]==0)
        {
            pr[cnt_p++]=i;
            if(i<=root)
            {
                for(j=i*i;j<=num;j+=2*i)
                    ara[j]=1;
            }
        }
    }
}
*/

struct ss
{
    i64 v,ind;
}stru[si];

bool cmp(ss aa, ss bb)
{
    if(aa.v==bb.v)
    return aa.ind<bb.ind;
    return aa.v<bb.v;
}

bool cmp1(ss aa, ss bb)
{
    return aa.ind<bb.ind;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    while(~scanf("%d",&n))
    {
        sm=cnt=0;
        fg=1;
        i64 mn=0;
        rep(i,0,n)
        {
            scanf("%d",&stru[i].v);
            stru[i].ind=i+1;
            mn=min(mn,stru[i].v);

        }

        sort(stru,stru+n,cmp);

        sm=0;
        rep(i,0,n)
        {
            mn=max(mn,stru[i].v);
            stru[i].v=mn;
            mn++;
        }

        sort(stru,stru+n,cmp1);
        rep(i,0,n)
        {
            if(!i)
            printf("%d",stru[i].v);
            else
            printf(" %d",stru[i].v);
        }
        puts("");

    }
    return 0;
}