# include<iostream>
# include<set>
#include <ios>
# include <algorithm>
using namespace std;
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m,k;
    cin>>n>>m>>k;
    long long mn=1000000001;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (i%2==0)
            mn=min(mn,a[i]);
    }
    if (n==1)
        cout<<min(m*k,(long long)a[0]);
    else
    {
        long long j=n/2+1;
        long long num=m/j;
        num*=k;
        num*=(n%2);
        cout<<min(num,mn)<<endl;;
    }
}