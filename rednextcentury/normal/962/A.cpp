#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for (int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    long long cur=0;
    for (int i=0;i<n;i++)
    {
        cur+=a[i];
        if (cur*2>=sum)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
}