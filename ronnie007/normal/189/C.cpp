#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


int n;
int a[200007];
int b[200007];
int used[200007];

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
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++)
        {
        scanf("%d",&b[i]);
        used[b[i]]=i;
        }
    }


void solve()
    {
    int i;
    int ind=1;
    for(i=0;i<n;i++)
        {
        a[i]=used[a[i]];
        }
    for(i=1;i<n;i++)
        {
        if(a[i]>a[i-1])ind=i+1;
        else break;
        }
    printf("%d\n",n-ind);
    }