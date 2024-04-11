#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 2e5 + 11;

int a[N],b[N];

int main()
{
    int n,w;
    cin>>n>>w;
    int d=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        w-=(a[i]+1)/2;
        b[i]=(a[i]+1)/2;
    }
    while (w>0)
    {
    int d=0;
    for (int i=1; i<=n; i++)
        if (a[i]>a[d]&&a[i]!=b[i]) d=i;
    int p=min(w,a[d]-b[d]);
    w-=p;
    b[d]+=p;
    }
    if (w<0) {cout<<-1<<endl; return 0;}
    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";
    cout<<endl;
}