#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int n;
int a[100007];
int b[100007];
int c[100007];

int used[100007];

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
    }


void solve()
    {
    int i;
    int g=0;
    int h=1;
    if(n==1)
        {
        printf("0\n0\n0\n");
        return ;
        }
    for(i=0;i<n;i++)
        {
        a[i]=g;
        b[i]=h;
        c[i]=(g+h)%n;
        if(used[c[i]]==1)
            {
            printf("-1\n");
            break;
            }
        used[c[i]]=1;
        g++;
        h++;
        g=g%n;
        h=h%n;
        ///cout<<g<<" "<<h<<"\n";
        }
    if(i==n)
        {
        for(i=0;i<n;i++)
            {
            printf("%d ",a[i]);
            }
        printf("\n");
        for(i=0;i<n;i++)
            {
            printf("%d ",b[i]);
            }
        printf("\n");
        for(i=0;i<n;i++)
            {
            printf("%d ",c[i]);
            }
        printf("\n");
        }
    }