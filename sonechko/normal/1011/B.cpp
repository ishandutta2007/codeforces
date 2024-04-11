#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 100 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    for (int ii=100; ii>=1; ii--)
    {
        int kk=0;
        for (int i=1; i<=100; i++)
            kk+=kol[i]/ii;
        if (kk>=n) {cout<<ii<<endl; return 0;}
    }
    cout<<0;
}