#include <bits/stdc++.h>
using namespace std;
int h[100009];
set<int> s[100009];
main()
{
    int n;
    cin >> n;
    s[0].insert(1);
    for (int i=2 ;i <= n; i++)
    {
        int p;
        cin >>p;
        h[i]=h[p]+1;
        s[h[i]].insert(i);
    }
    int ans=0;
    for (int i=0; i <= n; i++)
       ans+=s[i].size()%2;
    cout<<ans<<endl;
}