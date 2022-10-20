#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int n;
int a[100];

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
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    sort(a,a+n);
    }

void solve()
    {
    int br=1;
    int mx=0;
    int i;
    for(i=1;i<n;i++)
        {
        if(a[i]==a[i-1])br++;
        else
            {
            if(mx<br)mx=br;
            br=1;
            }
        }
    if(br>0)
        {
        if(mx<br)mx=br;
        br=1;
        }
    int lft=n-mx+1;
    if(mx>lft)printf("NO\n");
    else printf("YES\n");
    }