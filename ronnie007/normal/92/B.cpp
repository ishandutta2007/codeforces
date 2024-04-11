#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int br=0;
    string a;
    int i;
    int n;
    int br1=0;
    cin>>a;
    n=a.size();
    for(i=n-1;i>=0;i--)
        {
        if(a[i]=='1')br1++;
        else
            {
            br++;
            br+=br1;
            if(br1!=0)br1=1;
            }
        }
    if(br1>1)br+=(br1+1);
    ///if(a.size()==1)br=0;
    printf("%d\n",br);
    return 0;
    }