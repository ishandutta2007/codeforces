# include <iostream>
# include <algorithm>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
bool prime[1000001];
int main()
{
    int n;
    cin>>n;
    for (int i=2;i<=1000000;i++)
    {
        if (prime[i]==0)
        {
            for (int x=i+i;x<=1000000;x+=i)
                prime[x]=1;
        }
    }
    for (int i=2;i<n;i++)
    {
        if (prime[i] && prime[n-i])
        {
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
}