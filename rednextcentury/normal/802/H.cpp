#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    vector<pair<int,int> > ret;
    for (long long i=100000;i>=3;i--)
    {
        long long cur=i*(i-1)*(i-2)/6;
        int need = n/cur;
        n = n - cur*need;
        if (need)
            ret.push_back({i,need});
    }
    int last=0;
    int len=0;
    for (int i=ret.size()-1;i>=0;i--)
    {
        while(last<ret[i].first)cout<<'a',last++,len++;
        for (int j=0;j<ret[i].second;j++)
            cout<<'b',len++;
    }
    cout<<" aaab\n";
}