#include <bits/stdc++.h>
using namespace std;
multiset<pair<long long,int> > s;
long long ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        long long l,r;
        cin>>l>>r;
        s.insert(make_pair(l,0));
        s.insert(make_pair(r+1,1));
    }
    long long num=0;
    long long last=0;
    while(!s.empty())
    {
        pair<long long,int> p = *s.begin();
        long long cur=p.first;
        ret[num]+=cur-last;
        last=cur;
        s.erase(s.begin());
        if (p.second==0)
            num++;
        else
            num--;
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}