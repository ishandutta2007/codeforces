#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


int n;
int sz=1;
long long sum=0;
long long used[200007];
long long  v[200007];


void input();
void solve();


int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    }


void solve()
    {
    int i;
    int t;
    int a,b;
    double ans;
    for(i=0;i<n;i++)
        {
        scanf("%d",&t);
        if(t==1)
            {
            scanf("%d%d",&a,&b);
            used[a]+=b;
            sum+=((long long) a)*b;
            }
        if(t==2)
            {
            scanf("%d",&a);
            sum+=a;
            sz++;
            v[sz]=a;
            }
        if(t==3)
            {
            if(used[sz]!=0)
                {
                sum-=used[sz];
                used[sz-1]+=used[sz];
                used[sz]=0;
                }
            sum-=v[sz];
            sz--;
            }
        ans=double(sum)/sz;
        printf("%lf\n",ans);
        }
    }