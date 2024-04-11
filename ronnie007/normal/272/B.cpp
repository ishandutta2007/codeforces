#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int n;
int a[100007];

void input();
void solve();
int f(int x);


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    }

void solve()
    {
    int i;
    long long br=0;
    for(i=0;i<n;i++)
        {
        br=0;
        while(a[i]>0)
            {
            if(a[i]%2==1)br++;
            a[i]=a[i]/2;
            }
        a[i]=br;
        }
    sort(a,a+n);
    long long ans=0;
    br=1;
    for(i=1;i<n;i++)
        {
        //cout<<a[i]<<"\n";
        if(a[i]==a[i-1])br++;
        else
            {
            ans+=br*(br-1)/2;
            br=1;
            }
        }
    //cout<<br<<"\n";
    ans+=br*(br-1)/2;
    printf("%I64d\n",ans);
    }