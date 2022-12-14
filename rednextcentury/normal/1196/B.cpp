#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long long cur=0;
        vector<int> ans;
        for (int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            cur+=x;
            if (cur%2 && ans.size()+1<k)
            {
                ans.push_back(i);
                cur=0;
            }
        }
        int x;
        cin>>x;
        cur+=x;
        if (cur%2)ans.push_back(n);
        if (ans.size()==k)
        {
            cout<<"YES"<<endl;
            for (auto x:ans)cout<<x<<' ';
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}