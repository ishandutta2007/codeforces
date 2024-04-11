#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int mx=0;

void input();
void solve();


struct tuhla
    {
    int num;
    int pos;
    };



bool f(struct tuhla x,struct tuhla y);
struct tuhla a[1000000];

int main()
    {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
    int i;
    scanf("%d",&n);
    for(i=0;i<2*n;i++)
        {
        scanf("%d",&a[i].num);
        a[i].pos=i+1;
        }
    }


void solve()
    {
    sort(a,a+2*n,f);
    int i;
    for(i=0;i<2*n;i+=2)
        {
        if(a[i].num!=a[i+1].num)
            {
            printf("-1\n");
            return ;
            }
        }
    for(i=0;i<2*n;i+=2)
        {
        printf("%d %d\n",a[i].pos,a[i+1].pos);
        }
    }




bool f(struct tuhla x,struct tuhla y)
    {
    if(x.num<y.num)return true;
    return false;
    }