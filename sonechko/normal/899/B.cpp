#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
int good(int l)
{
    int xx=31;
    if (l==4||l==6||l==9||l==11) xx=30;
    if (l==2) xx=28;
    return xx;
}
int a[100];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=n; j++)
        if (a[j]==29)
    {
        int l=2;
        for (int x=j-1; x>=1; x--)
        {
            l--;
            if (l==0) l=12;
            if (good(l)!=a[x]) {cout<<"NO"<<endl; return 0;}
        }
        l=2;
        for (int x=j+1; x<=n; x++)
        {
            l++;
            if (l==13) l=1;
            if (good(l)!=a[x]) {cout<<"NO"<<endl; return 0;}
        }
        cout<<"YES"<<endl;
        return 0;
    }
    for (int p=1; p<=12; p++)
        if (a[1]==good(p))
    {
        int l=p;
        int tt=0;
        for (int x=2; x<=n; x++)
        {
            l++;
            if (l==13) l=1;
            if (good(l)!=a[x]) tt=1;
        }
        if (tt==0)
        {
            cout<<"YES"<<endl;
        return 0;
        }
    }
    cout<<"NO"<<endl;
}