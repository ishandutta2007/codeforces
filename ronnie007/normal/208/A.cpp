#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
    {
    string a;
    int i=0,j;
    int n;
    cin>>a;
    n=a.size();
    for(i=2;i<n;i++)
        {
        if(a[i]=='B' && a[i-1]=='U' && a[i-2]=='W')
            {
            a[i]='+';
            a[i-1]='+';
            a[i-2]='+';
            }
        }
    for(i=0;i<n;i++)
        {
        if((i==0 && a[i]!='+') || (a[i]!='+' && a[i-1]=='+'))
            {
            for(j=i;j<n;j++)
                {
                if(a[j]!='+')
                    {
                    cout<<a[j];
                    }
                else
                    {
                    cout<<" ";
                    break;
                    }
                }
            }
        }
    printf("\n");
    return 0;
    }