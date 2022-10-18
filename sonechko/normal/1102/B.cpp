#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;

int a[N],kol[N];
vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        v[a[i]].pb(i);
    }
    int pos=1;
    for (int i=1; i<=5000; i++)
    if (v[i].size()>k) {cout<<"NO"<<endl; return 0;} else
        {
            for (int j=0; j<v[i].size(); j++)
            {
                a[v[i][j]]=pos;
                pos++;
                if (pos>k) pos=1;
            }
        }
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}