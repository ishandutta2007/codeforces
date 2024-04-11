#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

bitset<20000> a[100],b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        for (int j=1; j<=l; j++)
        {
            int x;
            cin>>x;
            a[i][x]=1;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    {
        b=(a[i]&a[j]);
        if (b.count()==0) {cout<<"impossible"<<endl; return 0;}
    }
    cout<<"possible";
}