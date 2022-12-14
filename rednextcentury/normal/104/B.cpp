# include <iostream>
# include <string>
using namespace std;
long long a[10000000];
int main()
{
    int n;
    cin>>n;
    for (long long i=0;i<n;i++)
    {
        cin>>a[i];
        if (i!=n-1)
            a[i]--;
    }
    long long ans=0;
    for (long long i=0;i<n;i++)
    {
        ans+=(i+1)*a[i];
    }
    cout<<ans<<endl;




}