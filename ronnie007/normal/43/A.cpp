#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
    {
    string s;
    string a;
    string b;
    int br1=0;
    int br2=0;
    int i;
    int n;
    a="";
    b="";
   // cout<<a.size();
   // cout<<b.size();
    scanf("%d\n",&n);
    cin>>s;
    a=s;
    br1=1;
    for(i=0;i<n-1;i++)
        {
        cin>>s;
        if(a==s)br1++;
        else {b=s;br2++;}
        }
    //cout<<br1<<" "<<br2;
    if(br1>br2)cout<<a<<"\n";
    else cout<<b<<"\n";
    return 0;
    }