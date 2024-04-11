#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];
    int left[1000]={0},right[1000]={0};

        for(int i=1; i<n; i++)
        left[i] = (a[i]>=a[i-1] ? left[i-1]+1 : 0);

        for(int i=n-2;i>=0;i--)
            right[i] = (a[i] >= a[i+1] ? right[i+1] + 1 : 0);

    int maximal=0;
    for(int i=0;i<n;i++)
    {

        if(left[i]+right[i] +1 > maximal)
        {

            maximal = left[i] + right [i]+ 1;
        }
    }
    cout<<maximal;
}