#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int k=(n+1)/2;
            if(abs(i-k)+abs(j-k)<k) cout<<"D";
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}