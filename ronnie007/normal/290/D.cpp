#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    int x;
    cin>>a;
    cin>>x;
    int i;
    int n=a.size();
    for(i=0;i<n;i++)
        {
        if(a[i]>='a' && a[i]<='z')
            {
            if(a[i]-'a'<x)a[i]=(a[i]-'a')+'A';
            else a[i]=a[i]-'a'+'a';
            }
        else
            {
            if(a[i]-'A'<x)a[i]=(a[i]-'A')+'A';
            else a[i]=a[i]-'A'+'a';
            }
        }
    cout<<a<<"\n";
    return 0;
    }