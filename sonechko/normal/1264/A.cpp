#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N = 1e6 + 11;

int a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int p1=0,p2=0;
    for (int i=1; i<=n; i++)
        if (a[i]>a[i+1]) {p1=i; break;}
    for (int j=p1+1; j<=n; j++)
    if (j-p1>p1&&a[j]>a[j+1]) {p2=j; break;}
    int p3=0,ans=0;
    for (int j=n/2; j>p2; j--)
        if (a[j]>a[j+1]&&(j-p2)>p1)
    {
        ans=j;
        p3=j;
        break;
    }
    if (ans==0||p1==0||p2==0) cout<<0<<" "<<0<<" "<<0<<"\n"; else cout<<p1<<" "<<p2-p1<<" "<<p3-p2<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}