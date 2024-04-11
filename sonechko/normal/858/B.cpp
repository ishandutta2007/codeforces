#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
    }
    vector<int> v;
    for (int p=1; p<=200; p++)
    {
        int x=0;
        for (int i=1; i<=m; i++)
        {
            int d=(a[i]/p);
            if (a[i]%p!=0) d++;
            if (b[i]!=d) {x=1; break;}
        }
        if (x==0)
        {
            int d=(n/p);
            if (n%p!=0) d++;
            v.pb(d);
        }
    }
    sort(v.begin(),v.end());
    if (v[0]!=v[v.size()-1]) {cout<<-1<<endl;} else cout<<v[0]<<endl;
}