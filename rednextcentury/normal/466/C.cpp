# include <iostream>
# include <map>
# include <cmath>
# include <cstdlib>
# include <string>
using namespace std;
int n;
long long a[1000000];
map<long long,long long> m;
long long ans=0;
long long ans2=0;
long long ans1=0;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[n]/3*2 && i!=n)
            ans2+=ans1;
        if (a[i]==a[n]/3)
            ans1++;
    }
    if (a[n]%3!=0)
    {
        cout<<0<<endl;
    }
    else
    {

        cout<<ans2<<endl;
    }
}