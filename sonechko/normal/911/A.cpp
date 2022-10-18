#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ff first
#define ss second
const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int g=a[1];
    for (int i=1; i<=n; i++)
        if (a[i]<g) g=a[i];
    int pos=-100000000,res=100000000;
    for (int i=1; i<=n; i++)
        if (a[i]==g)
    {
        res=min(res,i-pos);
        pos=i;
    }
    cout<<res<<endl;
}