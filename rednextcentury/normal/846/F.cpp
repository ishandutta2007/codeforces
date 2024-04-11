#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000003];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    long long ret=0;
    for (int i=1;i<=1000000;i++)
    {
        int last=0;
        for (int j=0;j<v[i].size();j++)
        {
            long long nxt = (j+1<v[i].size())?v[i][j+1]:n;
            long long cur = v[i][j];
            ret+=(cur+1)*(nxt-cur)*2LL-1;
        }
    }
    cout<<setprecision(10)<<fixed<<(long double)ret*1.0/(n*n)<<endl;
}