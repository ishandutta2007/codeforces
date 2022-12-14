#include <bits/stdc++.h>

using namespace std;
long long a[1000000];
vector<long long> vec;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i>1)
            vec.push_back(a[i]-a[i-1]-1);
    }
    sort(vec.begin(),vec.end());
    long long ret=n;
    int num = (int)vec.size();
    num-=(k-1);
    for (int i=0;i<min((int)vec.size(),num);i++)
        ret+=vec[i];
    cout<<ret<<endl;
}