#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 300 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int kol1=n,kol2=n*2;
    int k1=0,k2=0;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        while (l>=4)
        {
            if (kol1>0) {kol1--;} else
            if (kol2>1) {kol2-=2;} else {cout<<"NO"<<endl; return 0;}
            l-=4;
        }
        if (l==3)
        {
            if (kol1>0) {kol1--;} else
            if (kol2>1) {kol2-=2;} else {cout<<"NO"<<endl; return 0;}
        }
        if (l==2)
        {
            if (kol2>0) {kol2--;} else k2++;
        }
        if (l==1)
        {
            k1++;
        }
    }
    int p=min(k1,kol2);
    k1-=p;
    kol2-=p;
    for (int j=1; j<=kol1; j++)
    {
        p=min(k1,kol2);
        k1-=p;
        kol2-=p;
        if (k1>0&&k2>0) {k1--; k2--;} else
        if (k1>1) {k1-=2;} else
        if (k2>1) {k2-=2; k1++;} else
        if (k2>0) k2--; else
        if (k1>0) k1--;
        p=min(k1,kol2);
        k1-=p;
        kol2-=p;
    }
    if (k2>0||k1>0) cout<<"NO"<<endl; else
    cout<<"YES"<<endl;
}