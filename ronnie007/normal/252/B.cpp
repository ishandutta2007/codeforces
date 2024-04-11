#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[100007];
int n;
int b[100007];
int c[100007];


bool f(int x,int y);
int ch();

int main()
    {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        b[i]=a[i];
        c[i]=a[i];
        }
    sort(b,b+n);
    sort(c,c+n,f);
    if(n<3)
        {
        printf("-1\n");
        return 0;
        }
    int fl1=0;
    for(i=0;i<n-1;i++)
        {
        if(a[i]!=a[i+1])
            {
            swap(a[i],a[i+1]);
            if(ch()==1)
                {
                printf("%d %d\n",i+1,i+2);
                return 0;
                }
            swap(a[i],a[i+1]);
            }
        }
    printf("-1\n");
    return 0;
    }



bool f(int x,int y)
    {
    if(x>y)return true;
    return false;
    }

int ch()
    {
    int i;
    int fl1=0;
    int fl2=0;
    for(i=0;i<n;i++)
        {
        if(a[i]!=b[i])fl1=1;
        if(a[i]!=c[i])fl2=1;
        if(fl1==1 && fl2==1)return 1;
        }
    return 0;
    }