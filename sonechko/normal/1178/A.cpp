#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    int s1=0,s2=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (i==1) {v.pb(i); s1+=a[i];}
        if (i>=2&&a[i]*2<=a[1])
        {
            v.pb(i);
            s1+=a[i];
        }
        s2+=a[i];
    }
    if (s1*2>s2)
    {
        cout<<v.size()<<endl;
        for (int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;
    } else cout<<0;
}