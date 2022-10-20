#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
    {
    string a,b,c;
    int n,n1,n2;
    int i,j;
    cin>>a>>b>>c;
    n=a.size();
    n1=b.size();
    n2=c.size();
    if(n+n1!=n2)
        {
        printf("NO\n");
        return 0;
        }
    int fl=0;
    for(i=0;i<n;i++)
        {
        fl=0;
        for(j=0;j<n2;j++)
            {
            if(a[i]==c[j])
                {
                c[j]='+';
                fl=1;
                break;
                }
            }
        if(fl==0)
            {
            printf("NO\n");
            return 0;
            }
        }

    for(i=0;i<n1;i++)
        {
        fl=0;
        for(j=0;j<n2;j++)
            {
            if(b[i]==c[j])
                {
                c[j]='+';
                fl=1;
                break;
                }
            }
        if(fl==0)
            {
            printf("NO\n");
            return 0;
            }
        }
    printf("YES\n");
    return 0;
    }