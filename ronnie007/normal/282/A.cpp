#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    int n;
    int x=0;
    int i;
    string a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        cin>>a;
        if(a[0]=='+' || a[2]=='+')x++;
        else x--;
        }
    printf("%d\n",x);
    return 0;
    }