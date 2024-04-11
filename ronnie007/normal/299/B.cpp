#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n,k;
    string a;
    int i;
    cin>>n>>k;
    cin>>a;
    int br=0;
    for(i=1;i<n;i++)
        {
        if(a[i]=='.')
            {
            if(br>=k){printf("NO\n");return 0;}
            br=0;
            }
        else br++;
        }
    printf("YES\n");
    return 0;
    }