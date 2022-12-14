#include <bits/stdc++.h>
using namespace std;
vector<long long> divs;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,k;
    cin>>n>>k;
    if (k>1000000000)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (k*(k+1)/2 > n)
    {
        cout<<-1<<endl;
        return 0;
    }

    for (long long i=1;i*i<=n;i++)
    {
        if (n%i)continue;
        divs.push_back(i);
        if (n/i != i)
            divs.push_back(n/i);
    }
    sort(divs.begin(),divs.end());
    for (int i=divs.size()-1;i>=0;i--)
    {
        long long x=n/divs[i];
        if (k*(k+1)/2 > x)continue;
        long long sum=x;
        for (int j=0;j+1<k;j++)
        {
            cout<<(j+1)*divs[i]<<' ';
            x-=(j+1);
        }
        cout<<divs[i]*x<<endl;
        return 0;
    }
}