#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    string a;
    cin>>a;
    int n=a.size();
    int i;
    int x;
    
    for(i=0;i<n;i++)
        {
        if(a[i]=='.')break;
        }
    x=i-1;
    if(a[x]=='9'){printf("GOTO Vasilisa.\n");return 0;}

    if(a[x+2]>='5')
        {
        for(i=0;i<x;i++)
            {
            cout<<a[i];
            }
        a[x]++;
        cout<<a[x];
        }
    else
        {
        for(i=0;i<=x;i++)
            {
            cout<<a[i];
            }
        }
    return 0;
    }