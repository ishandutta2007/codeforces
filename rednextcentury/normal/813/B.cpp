#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long l,r;
long long mx=1000000000000000000LL;
vector<long long> getAll(long long x)
{
    vector<long long> ret;
    long long num=1;
    while(1)
    {
        if (num<=mx)
            ret.push_back(num);
        if (mx/num >= x)
            num=num*x;
        else
            break;
    }
    return ret;
}
int main()
{
    fast
    long long x,y;
    cin>>x>>y>>l>>r;
    vector<long long> a=getAll(x),b=getAll(y);
    set<long long> s;
    s.insert(l-1);
    s.insert(r+1);
    for (int i=0;i<a.size();i++)
        for (int j=0;j<b.size();j++)
            if (a[i]+b[j]>=l && a[i]+b[j]<=r)
                s.insert(a[i]+b[j]);
    long long last=-1;
    long long sol=0;
    for (set<long long>::iterator it=s.begin();it!=s.end();it++)
    {
        long long cur=*it;
        if (last!=-1)
            sol=max(sol,cur-last-1);
        last=cur;
    }
    cout<<sol<<endl;
}