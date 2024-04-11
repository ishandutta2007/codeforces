#include<bits/stdc++.h>

using namespace std;
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    long double ret=0;
    long long sum=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if (i>=k)
            sum-=a[i-k];
        if (i>=k-1)
            ret+=sum;
    }
    cout<<setprecision(10)<<fixed<<ret/(n-k+1)<<endl;
}