#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
    {
    string a;
    int i=0;
    int n;
    cin>>a;
    n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]=='h')break;
        }
    if(i==n)
        {
        printf("NO\n");
        return 0;
        }
    i++;
    for(;i<n;i++)
        {
        if(a[i]=='e')break;
        }
    if(i==n)
        {
        printf("NO\n");
        return 0;
        }
        i++;
    for(;i<n;i++)
        {
        if(a[i]=='l')break;
        }
    if(i==n)
        {
        printf("NO\n");
        return 0;
        }
    i++;
    for(;i<n;i++)
        {
        if(a[i]=='l')break;
        }
    if(i==n)
        {
        printf("NO\n");
        return 0;
        }
    i++;
    for(;i<n;i++)
        {
        if(a[i]=='o')break;
        }
    if(i==n)
        {
        printf("NO\n");
        return 0;
        }
    printf("YES\n");
    return 0;
    }