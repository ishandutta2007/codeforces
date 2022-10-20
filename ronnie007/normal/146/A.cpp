#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
    {
    int n;
    string a;
    int s1=0;
    int s2=0;
    int i,j;
    cin>>n;
    cin>>a;
    for(i=0;i<n/2;i++)
        {
        s1+=(a[i]-'0');
        s2+=(a[n-i-1]-'0');
        if(a[i]!='4' && a[i]!='7')
            {
            printf("NO\n");
            return 0;
            }
        if(a[n-i-1]!='4' && a[n-i-1]!='7')
            {
            printf("NO\n");
            return 0;
            }
        }
    if(s1!=s2)
        {
        printf("NO\n");
        return 0;
        }
    printf("YES\n");
    return 0;
    }