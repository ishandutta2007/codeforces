#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    n++;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    int gg=0;
    for (int i=2; i<=n; i++)
    if (a[i-1]>1&&a[i]>1)
    {
        gg=1;
    }
    if (gg==0) {cout<<"perfect"<<endl; return 0;}
    cout<<"ambiguous"<<endl;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        int ks=a[i];
        int pp=p;
        while (ks>0)
        {
            ks--;
            p++;
            cout<<pp<<" ";
        }
    }
    cout<<endl;
    p=0;
    int ps=0;
    for (int i=1; i<=n; i++)
    {
        int pp=p;
        if (a[i-1]>1&&a[i]>1&&ps==0)
        {
            cout<<p-1<<" ";
            p++;
            a[i]--;
            ps=1;
        }
        int ks=a[i];
        while (ks>0)
        {
            ks--;
            p++;
            cout<<pp<<" ";
        }
    }
}