#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ss=0;
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]%2==0) {a[i]/=2; ss+=a[i];} else
        {
            a[i]=(a[i]-1)/2;
            ss+=a[i];
            vv.pb(i);
        }
    }
    while (ss<0)
    {
        ss++;
        int l=vv.back();
        a[l]++;
        vv.pop_back();
    }
    for (int i=1; i<=n; i++)
        cout<<a[i]<<"\n";
}