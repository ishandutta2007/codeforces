#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    int n,m;
    string a[17];
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        }
    int ans=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='W')
                {
                if(i>0 && a[i-1][j]=='P'){ans++;continue;}
                if(i<n-1 && a[i+1][j]=='P'){ans++;continue;}
                if(j>0 && a[i][j-1]=='P'){ans++;continue;}
                if(j<m-1 && a[i][j+1]=='P'){ans++;continue;}
                }
            }
        }
    cout<<ans<<"\n";
    return 0;
    }