#include <bits/stdc++.h>
using namespace std;
multiset<long long> s;
pair<long long,long long> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    long long ret=0;
    for (long long i=2;i+1<=n;i++)
    {
        ret+=i*(i+1);
    }
    cout<<ret<<endl;
}