#include<bits/stdc++.h>
using namespace std;
int best[11][11][11];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<pair<int,int> > ret;
        for (long long i=100000;i>=2;i--)
        {
            long long cur=i*(i-1)/2;
            int need = n/cur;
            n = n - cur*need;
            if (need)
                ret.push_back({i,need});
        }
        cout<<1;
        int last=0;
        for (int i=ret.size()-1;i>=0;i--)
        {
            while(last<ret[i].first)cout<<3,last++;
            for (int j=0;j<ret[i].second;j++)
                cout<<7;
        }
        cout<<endl;
    }
}