#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;



int n;
int a[150];



void input();
void solve();

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
    sort(a,a+n);
    }

void solve()
    {
    int br=0;
    vector <int> v;
    v.clear();
    int i;
    if(a[0]==0)v.push_back(0);
    if(a[n-1]==100)v.push_back(100);
    int f=0;
    int f1=0;
    for(i=0;i<n;i++)
        {
        if(f==0 && a[i]>0 && a[i]<10){v.push_back(a[i]);f=1;}
        if(f1==0 && a[i]%10==0 && a[i]>=10 && a[i]<=99){v.push_back(a[i]);f1=1;}
        }
    if(f==0 && f1==0)
        {
        for(i=0;i<n;i++)
            {
            if(a[i]!=0 && a[i]!=100){v.push_back(a[i]);break;}
            }
        }
    printf("%d\n",v.size());
    for(i=0;i<v.size();i++)
        {
        printf("%d ",v[i]);
        }
    }