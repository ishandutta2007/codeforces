#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long v[1000000];
long long num[1000000];
long long best=-1;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        long long x = a[i];
        int cur=0;
        while(x%2==0)x/=2,cur++;
        v[i]=cur;
        num[cur]++;
        if (num[cur]>ans)ans=num[cur],best=cur;
    }
    vector<long long> ret;
    for (int i=0;i<n;i++)
        if (v[i]!=best)ret.push_back(a[i]);
    cout<<ret.size()<<endl;
    for (auto x:ret)cout<<x<<' ';
}