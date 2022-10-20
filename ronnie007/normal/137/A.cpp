#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n;
    int br=1;
    int br1=0;
    string a;
    cin>>a;
    int i;
    n=a.size();
    for(i=1;i<n;i++)
        {
        if(a[i]==a[i-1])
            {
            br++;
            }
        else
            {
            br1++;
            br=1;
            }
        if(br==6)
            {
            br=1;
            br1++;
            }
        }
    printf("%d\n",br1+1);
    return 0;
    }