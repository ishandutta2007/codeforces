#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 100 + 11;

vector<int> v[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l].pb(i);
    }
    int k1=0,k2=0;
    for (int i=1; i<=100; i++)
        if ((int)v[i].size()==1)
        {
            if (k1==k2) {k1++; ans[v[i].back()]=1;} else {k2++; ans[v[i].back()]=2;}
            v[i].pop_back();
        }
    for (int i=1; i<=100; i++)
    {
        if (k1!=k2&&v[i].size()>2)
        {
            k2++;
            ans[v[i].back()]=2;
            v[i].pop_back();
        }
        for (int j=0; j<v[i].size(); j++)
            ans[v[i][j]]=1;
    }
    if (k1!=k2) return cout<<"NO", 0;
    cout<<"YES\n";
    for (int i=1; i<=n; i++)
        if (ans[i]==1) cout<<"A"; else cout<<"B";
}
/**

**/