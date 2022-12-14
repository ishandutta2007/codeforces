#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int mn=1e9;
    deque<int> q;
    set<int> s;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mn=min(mn,x);
        q.push_back(x);
        s.insert(x);
    }
    if (s.size()==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if (q.front()==mn && q.back()!=mn)
        {
            int ok=1;
            for (int i=1;i<n;i++)
                if (q[i]<q[i-1])ok=0;
            if (!ok)cout<<-1<<endl;
            else cout<<i-1<<endl;
            return 0;
        }
        int x = q.back();
        q.pop_back();
        q.push_front(x);
    }
    cout<<-1<<endl;
}