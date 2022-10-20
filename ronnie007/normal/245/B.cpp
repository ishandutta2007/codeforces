#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    string a;
    cin>>a;
    int i;
    int n=a.size();
    string b;
    int sz;
    if(a[0]=='h')sz=4;
    else sz=3;
    for(i=0;i<sz;i++)
        {
        b+=a[i];
        }
    b+="://";
    for(i=sz;i<n;i++)
        {
        if(i!=sz && a[i]=='r' && a[i+1]=='u')
            {
            break;
            }
        else
            {
            b+=a[i];
            }
        }
    b+=".ru";
    if(i+2==n){cout<<b<<"\n";return 0;}
    b+="/";
    sz=i;
    sz+=2;
    for(i=sz;i<n;i++)
        {
        b+=a[i];
        }
    cout<<b<<"\n";
    return 0;
    }