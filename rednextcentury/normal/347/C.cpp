#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
long long GCD(long long a,long long b)
{
    if (a<b)swap(a,b);
    if (b==0)return a;
    if (a%b==0)return b;
    return GCD(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long mx=0;
    long long gcd;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (i==0)gcd=a[i];
        else gcd=GCD(a[i],gcd);
        mx=max(mx,a[i]);
    }
    if ((mx/gcd-n)%2)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}