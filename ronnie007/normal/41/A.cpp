#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    string b;
    cin>>a;
    cin>>b;
    if(a.size()!=b.size()){printf("NO\n");return 0;}
    int i;
    int n;
    n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]!=b[n-i-1])
            {
            printf("NO\n");
            return 0;
            }
        }
    printf("YES\n");
    return 0;
    }