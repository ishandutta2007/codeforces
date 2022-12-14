#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
multiset<int> A;
multiset<int> B;
int ret = 2000000000;
int id = -1;
int h;
void solve(int x)
{
    int mnF = +2000000000;
    int mxF = -2000000000;
    if (A.size()>=2)
    {
        mnF = min(mnF, *(A.begin())+*(++A.begin()));
        mxF = max(mxF, *(A.rbegin())+*(++A.rbegin()));
    }
    if (B.size()>=2)
    {
        mnF = min(mnF, *(B.begin())+*(++B.begin()));
        mxF = max(mxF, *(B.rbegin())+*(++B.rbegin()));
    }
    if (A.size() && B.size())
    {
        mnF = min(mnF, *(A.begin())+*(B.begin())+h);
        mxF = max(mxF, *(A.rbegin())+*(B.rbegin())+h);
    }
    if (mxF-mnF<ret)
        ret = mxF - mnF, id = x;
}
int ans[1000000];
int main()
{
    int n;
    cin>>n>>h;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i+1;
        B.insert(a[i].first);
    }
    solve(0);
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        A.insert(a[i].first);
        B.erase(B.find(a[i].first));
        solve(i+1);
    }
    for (int i=0;i<id;i++)
        ans[a[i].second]=1;
    for (int i=id;i<n;i++)
        ans[a[i].second]=2;
    cout<<ret<<endl;
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}