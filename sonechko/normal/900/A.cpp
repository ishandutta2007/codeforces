#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ss second
#define ff first
const ll N = 1e6 + 11;
int x[N],y[N];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol1=0,kol2=0;
    for (int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
        if (x[i]>0) kol1++; else kol2++;
    }
    if (kol1<=1||kol2<=1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}