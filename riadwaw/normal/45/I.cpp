#include<stdio.h>
#include<string.h>
#include <string>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include <map>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int n,a[110],i;
    int j,w=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a, a+n);
    reverse(a, a+n);
    i=0;
    int q=1;
    if(n==1){
        cout<<a[0];
        return 0;
    }


    if(a[0]<=0)
    {
        i=0;
        while(a[i]==0 && i<n)
            i++;
        if(i>=n-1)
        {
            cout<<"0";
            return 0;
        }
        else
        {
            for(j=n-1;j>i;j--)
            {
                w++;
                cout<<a[j]<<' ';
            }
            if(w%2)
            {
                cout<<a[i]<<' ';
                return 0;
            }
            return 0;
        }
    }




    while(a[i]>0 && i<n)
    {
        cout<<a[i]<<' ';
        i++;
    }
    if(i==n)
    {
        return 0;
    }
    while(a[i]==0 && i<n)
        i++;
    if(i==n || i==n-1)
    {
        return 0;
    }
    for(j=n-1;j>i;j--)
    {
        w++;
        cout<<a[j]<<' ';
    }
    if(w%2)
    {
        cout<<a[i]<<' ';
        return 0;
    }
    return 0;
}