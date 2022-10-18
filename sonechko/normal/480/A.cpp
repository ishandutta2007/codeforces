#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair

const int N = 5000 + 11;

pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff>>a[i].ss;
    }
    sort(a+1,a+n+1);
    int c=0;
    for (int i=1; i<=n; i++)
        if (a[i].ss>=c) c=a[i].ss; else
        c=a[i].ff;
    cout<<c<<endl;
}