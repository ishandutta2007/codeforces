#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a,b;
    int n,m;
    int i;
    cin>>a>>b;
    n=a.size();
    m=b.size();
    int x1=-1;
    int x2=-1;
    if(m!=n)
        {
        printf("NO\n");
        return 0;
        }
    int br=0;
    for(i=0;i<n;i++)
        {
        if(a[i]!=b[i])
            {
            br++;
            if(x1==-1)
                {
                x1=i;
                }
            else
                {
                if(x2==-1)x2=i;
                else
                    {
                    printf("NO\n");
                    return 0;
                    }
                }
            }
        }
    if(br==2)
        {
        if(a[x1]==b[x2] && a[x2]==b[x1])printf("YES\n");
        else printf("NO\n");
        }
    else printf("NO\n");
    return 0;
    }