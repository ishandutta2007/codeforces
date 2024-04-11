#include<bits/stdc++.h>
using namespace std;
long long n;
vector<long long> vec;
void add(long long x)
{
    long long mx = n/(x)-(n%x==0);
    vec.push_back(x*mx*(mx+1)/2+n/x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (long long i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            add(i);
            if (i!=n/i)add(n/i);
        }
    }
    sort(vec.begin(),vec.end());
    for (auto x:vec)
        cout<<x<<' ';
    cout<<endl;
}