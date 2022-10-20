#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    int k;
    int u[50];
    int i,j,t;
    for(i=0;i<50;i++)
        {
        u[i]=0;
        }
    cin>>k;
    cin>>a;
    int n=a.size();
    for(i=0;i<n;i++)
        {
        u[a[i]-'a']++;
        }
    for(i=0;i<50;i++)
        {
        if(u[i]%k!=0)
            {
            printf("-1\n");
            return 0;
            }
        }
    for(i=0;i<k;i++)
        {
        //cout<<u[i]<<"\n";
        for(j=0;j<26;j++)
            {
             if(u[j]!=0)
                {
                for(t=0;t<u[j]/k;t++)
                    {
                    cout<<char(j+'a');
                    }
                }
            }
        }
    cout<<"\n";
    return 0;
    }