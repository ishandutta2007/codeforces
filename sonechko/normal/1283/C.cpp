#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 2e5 + 11;

int d[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
    {
        cin>>d[i];
        use[d[i]]=1;
        if (d[i]==0) v1.pb(i);
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0) v2.pb(i);
    while (v1.size()>2)
    {
        int l=v1.back();
        if (v2.back()==l) {v2.pop_back(); d[l]=v2.back(); v2.back()=l;} else
        {
            d[l]=v2.back();
            v2.pop_back();
        }
        v1.pop_back();
    }
    if (v1[0]==v2[0]||v1[1]==v2[1]) swap(v1[0],v1[1]);
    d[v1[0]]=v2[0];
    d[v1[1]]=v2[1];
    for (int i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}