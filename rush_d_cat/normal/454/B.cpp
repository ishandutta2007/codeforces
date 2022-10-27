#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;
int a[400000+10];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    int l=1,r=2;
    while(r<=(2*n))
    {
        if(a[r]>=a[r-1])
        {
            if((r-l+1)==n)
            {
                cout<<(n+1-l)%n<<endl;
                return 0;
            }
            r++;
        }else{
            l=r;
            r++;
        }
    }
    cout<<-1<<endl;
    return 0;
}