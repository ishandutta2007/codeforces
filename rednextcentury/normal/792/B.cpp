#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int n;
int rem(int l,int num)
{
    int c=0;
    for (int i=0;i<n;i++)
        if (b[i]==l)
            c=i;
    for (int i=0;i<num;i++)
    {
        c++;
        c=c%n;
    }
    cout<<b[c]<<' ';
    for (int i=c+1;i<n;i++)
        swap(b[i],b[i-1]);
    n--;
    c=c%n;
    return b[c];
}
int main()
{
    int k;
    cin>>n>>k;
    for (int i=0;i<k;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        b[i]=i+1;
    }
    int lead=1;
    for (int i=0;i<k;i++)
    {
        lead=rem(lead,a[i]%n);
    }
}