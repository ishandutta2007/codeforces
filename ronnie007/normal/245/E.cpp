#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
    {
    string a;
    cin>>a;
    int n=a.size();
    int i;
    int x=0;
    int y=0;
    int balance=0;
    int br=0;
    int mx=0;
    int mn=1000000000;
    for(i=0;i<n;i++)
        {
        if(a[i]=='+')
            {
            balance++;
            }
        else
            {
            balance--;
            }
        if(mn>balance)mn=balance;
        if(mx<balance)mx=balance;
        }
    if(mn>0)mn=0;
    printf("%d\n",mx+abs(mn));
    return 0;
    }