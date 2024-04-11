#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000005];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for (int i=0;i<n;i++)cin>>a[i],sum+=a[i],vec[a[i]].push_back(i+1);
    sort(a,a+n);
    vector<int> ret;
    if (n>1 && vec[a[n-1]].size()==1)
    {
        if (sum-a[n-1]-a[n-2]==a[n-2])
            ret.push_back(vec[a[n-1]][0]);
    }

    long long need = sum-a[n-1]-a[n-1];
    if (need>0 && need<=1000000 &&  (need!=a[n-1] || vec[need].size()>1))
        for (int i=0;i<vec[need].size();i++)
            ret.push_back(vec[need][i]);
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';

}