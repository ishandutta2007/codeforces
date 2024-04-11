#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;


struct tuhla
    {
    int a;
    int b;
    };

struct tuhla v[100007];

bool f(struct tuhla x,struct tuhla y);



int main()
    {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&v[i].a,&v[i].b);
        }
    int l=1;
    sort(v,v+n,f);
    long long ans=0;
    for(i=0;i<n;i++)
        {
        if(l>0)
            {
            l--;
            l+=v[i].b;
            ans+=v[i].a;
            }
        }
    cout<<ans<<"\n";
    return 0;
    }



bool f(struct tuhla x,struct tuhla y)
    {
    if(x.b<y.b)return false;
    if(x.b>y.b)return true;
    if(x.a>y.a)return true;
    return false;
    }