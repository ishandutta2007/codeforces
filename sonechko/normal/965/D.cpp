#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l;
    cin>>n>>l;
    n--;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    a[0]=1e9;
    a[n+1]=1e9;
    int pos=0;
    for (int i=1; i<=n+1; i++)
    {
        if (i-pos>l) pos++;
        int pp=0;
        while (pos<i)
        {
            int d=min(a[pos],a[i]-pp);
            a[pos]-=d;
            pp+=d;
            if (a[pos]!=0) break;
            pos++;
        }
        a[i]=pp;
    }
    cout<<a[n+1]<<endl;
}