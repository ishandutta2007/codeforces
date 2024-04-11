#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

pair<int,int> a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].ff>>a[i].ss;
    for (int i=1; i<=n; i++)
        cin>>b[i].ff>>b[i].ss;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    cout<<a[1].ff+b[1].ff<<" "<<a[1].ss+b[1].ss<<endl;
}