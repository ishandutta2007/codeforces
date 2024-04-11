#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
    {
    int n;
    int i;
    string a,b;
    cin>>a;
    cin>>b;
    n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]!=b[i])printf("1");
        else printf("0");
        }
    printf("\n");
    return 0;
    }