#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
    long long k,n;
    cin>>n>>k;
    long long sum=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum%k) {
        cout<<"No"<<endl;
        return 0;
    }
    sum/=k;
    int s=0;
    long long cur=0;
    vector<int> ret;
    for (int i=0;i<n;i++)
    {
        cur+=a[i];
        s++;
        if (cur==sum)
        {
            cur=0;
            ret.push_back(s);
            s=0;
        }
    }
    if (ret.size()==k)
    {
        cout<<"Yes"<<endl;
        for (int i=0;i<ret.size();i++)
        {
            cout<<ret[i];
            if (i+1<ret.size())cout<<' ';
        }
        cout<<endl;
    } else {
        cout<<"No"<<endl;
    }
}