#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    n++;
    a[n]=1;
    vector<int> v;
    for (int i=1; i<=n; i++)
        if (a[i]==1&&i!=1) v.pb(a[i-1]);
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
/**

**/