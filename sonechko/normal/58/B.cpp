#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    v.pb(1);
    for (int d=2; d<=n; d++)
    {
        while (n%d==0)
        {
            v.pb(d);
            n/=d;
        }
    }
    for (int i=1; i<v.size(); i++)
        v[i]=v[i-1]*v[i];
    for (int i=v.size()-1; i>=0; i--)
        cout<<v[i]<<" ";
    cout<<endl;
}