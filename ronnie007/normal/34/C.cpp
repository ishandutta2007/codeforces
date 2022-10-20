#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int f[1050];

int main()
    {
    string a;
    string ans;
    int x=0;
    int i;
    int n;
    int l,r;
    int fl=0;
    l=-1;
    r=-1;
    cin>>a;
    n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]==',')
            {
            f[x]=1;
            x=0;
            }
        else x=x*10+(a[i]-'0');
        }
        f[x]=1;
        x=0;
    for(i=1;i<=1000;i++)
        {
        if(f[i]==1)
            {
            if(l==-1)l=i;
            r=i;
            }
        else
            {
            if(r!=-1 && l!=-1)
                {
                if(fl==1)printf(",");
                if(r!=l)printf("%d-%d",l,r);
                else printf("%d",r);
                fl=1;
                }
            r=-1;
            l=-1;
            }
        }
    if(r!=-1 && l!=-1)
        {
        if(fl==1)printf(",");
        if(r!=l)printf("%d-%d",l,r);
        else printf("%d",r);
        fl=1;
        }
    return 0;
    }