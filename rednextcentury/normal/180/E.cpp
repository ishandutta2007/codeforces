#include <bits/stdc++.h>
using namespace std;
int a[1000000];
set<pair<int,int> > s;
int num[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
        s.insert(make_pair(0,i));
    for (int i=0;i<n;i++)
        cin>>a[i];
    int l=0;
    int ans=0;
    for (int r=0;r<n;r++)
    {
        pair<int,int> x = *s.find(make_pair(num[a[r]],a[r]));
        x.first++;
        s.erase(s.find(make_pair(num[a[r]],a[r])));
        s.insert(x);
        num[a[r]]++;

        while(1)
        {
            pair<int,int> x = *(--s.end());
            if ((r-l+1)-x.first <= k)break;
            s.erase(s.find(make_pair(num[a[l]],a[l])));
            s.insert(make_pair(--num[a[l]],a[l]));
            l++;
        }

        ans=max(ans,(--s.end())->first);
    }
    cout<<ans<<endl;
}