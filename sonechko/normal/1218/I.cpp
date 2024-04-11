#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;

int a[N][N],b[N][N],c[N],aa[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char c;
        cin>>c;
        if (c=='1') a[i][j]=1;
        aa[i][j]=a[i][j];
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char c;
        cin>>c;
        if (c=='1') b[i][j]=1;
    }
    int p=0;
    for (int i=1; i<=n; i++)
    {
        char cc;
        cin>>cc;
        if (cc=='1') {c[i]=1; p=i;}
    }
    if (p==0)
    {
        int t=0;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        if (a[i][j]!=b[i][j]) t=1;
        if (t==0) {cout<<0; return 0;}
        cout<<-1;
        return 0;
    }

    vector<int> v1,v2;
    for (int j=1; j<=n; j++)
        if (a[p][j]!=b[p][j])
    {
        v2.pb(j);
        for (int i=1; i<=n; i++)
            a[i][j]=(a[i][j]+c[i])%2;
    }
    for (int i=1; i<=n; i++)
    {
        int cc=0;
        for (int j=1; j<=n; j++)
            if (a[i][j]!=b[i][j]) cc=1;
        if (cc)
        {
            v1.pb(i);
            for (int j=1; j<=n; j++)
                a[i][j]=(a[i][j]+c[j])%2;
        }
    }
    int t=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
        if (a[i][j]!=b[i][j]) t=1;
    if (t==0)
    {
        cout<<v1.size()+v2.size()<<"\n";
        for (int j=0; j<v1.size(); j++)
            cout<<"row "<<v1[j]-1<<"\n";
        for (int j=0; j<v2.size(); j++)
            cout<<"col "<<v2[j]-1<<"\n";
        exit(0);
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    a[i][j]=aa[i][j];


    v1.clear();
    v2.clear();
    for (int j=1; j<=n; j++)
        a[p][j]=(a[p][j]+c[j])%2;
    v1.pb(p);
    for (int j=1; j<=n; j++)
        if (a[p][j]!=b[p][j])
    {
        v2.pb(j);
        for (int i=1; i<=n; i++)
            a[i][j]=(a[i][j]+c[i])%2;
    }
    for (int i=1; i<=n; i++)
    {
        int cc=0;
        for (int j=1; j<=n; j++)
            if (a[i][j]!=b[i][j]) cc=1;
        if (cc)
        {
            v1.pb(i);
            for (int j=1; j<=n; j++)
                a[i][j]=(a[i][j]+c[j])%2;
        }
    }
    t=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
        if (a[i][j]!=b[i][j]) t=1;
    if (t==0)
    {
        cout<<v1.size()+v2.size()<<"\n";
        for (int j=0; j<v1.size(); j++)
            cout<<"row "<<v1[j]-1<<"\n";
        for (int j=0; j<v2.size(); j++)
            cout<<"col "<<v2[j]-1<<"\n";
        exit(0);
    }
    cout<<"-1";
    return 0;
}
/**
11
11

00
01
**/