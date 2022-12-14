# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
    long long n,d,m,l;
    cin>>n>>d>>m>>l;
    long long s=0,e=l;
    long long x=0;
    for (long long i=1;i<=n;i++)
    {
        if (x<=e)
            x=x+d*((e-x)/d +1);
        s+=m*(i<n),e+=m*(i<n);
        if (x<s || (x>e && i>=n))
        {
            cout<<x<<endl;
            return 0;
        }
    }
    cout<<x+d<<endl;
}