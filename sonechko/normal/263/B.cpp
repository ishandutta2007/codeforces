#include<bits/stdc++.h>

using namespace std;

int a[50];
int n,i,j,m,l;

int main()
{
    cin>>n>>m;
    for (i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for (i=0; i<n; i++)
     for (j=i; j<n; j++)
      if (a[i]<a[j])
       {
           l=a[i];
           a[i]=a[j];
           a[j]=l;
       }
    if (m>n)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<a[m-1]<<' '<<0<<endl;
    }
}