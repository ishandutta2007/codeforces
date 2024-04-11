#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,k;
    cin>>n>>k;
    long long sum=0;
    for (long long i=1;i<=1000000;i++)
    {
        long long sum=(i*(i+1))/2;
        if (sum>=k && i+(sum-k)==n)
        {
            cout<<sum-k<<endl;
            return 0;
        }
    }
}