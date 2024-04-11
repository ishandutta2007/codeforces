#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;
int a[N][5];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=k; j++)
        cin>>a[i][j];
    if (k==1)
    {
        for (int i=1; i<=n; i++)
        if (a[i][1]==0) {cout<<"YES"<<endl; return 0;}
        cout<<"NO"<<endl;
        return 0;
    }
    if (k==2)
    {
        int kol=0;
        for (int i=1; i<=n; i++)
        if (a[i][1]==0) {kol++; break;}
        for (int i=1; i<=n; i++)
        if (a[i][2]==0) {kol++; break;}
        if (kol==2) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        return 0;
    }
    if (k==3)
    {
        for (int i=1; i<=n; i++)
        if (a[i][1]+a[i][2]+a[i][3]==0) {cout<<"YES"<<endl; return 0;}
        int kol1=0,kol2=0,kol3=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i][1]==0) kol1++;
            if (a[i][2]==0) kol2++;
            if (a[i][3]==0) kol3++;
        }
        for (int i=1; i<=n; i++)
        {
            if (a[i][1]==0&&a[i][2]==0&&kol3>0) {cout<<"YES"<<endl; return 0;}
            if (a[i][1]==0&&a[i][3]==0&&kol2>0) {cout<<"YES"<<endl; return 0;}
            if (a[i][2]==0&&a[i][3]==0&&kol1>0) {cout<<"YES"<<endl; return 0;}
        }
        cout<<"NO"<<endl;
        return 0;
    }
    if (k==4)
    {
        int kol1=0,kol2=0,kol3=0,kol4=0;
        int kol12=0,kol13=0,kol14=0;
        int kol23=0,kol24=0;
        int kol34=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i][1]==0&&a[i][2]==0&&a[i][3]==0&&a[i][4]==0) {cout<<"YES"<<endl; return 0;}
            if (a[i][1]==0) kol1++;
            if (a[i][2]==0) kol2++;
            if (a[i][3]==0) kol3++;
            if (a[i][4]==0) kol4++;
            if (a[i][1]==0&&a[i][2]==0) kol12++;
            if (a[i][1]==0&&a[i][3]==0) kol13++;
            if (a[i][1]==0&&a[i][4]==0) kol14++;
            if (a[i][2]==0&&a[i][3]==0) kol23++;
            if (a[i][2]==0&&a[i][4]==0) kol24++;
            if (a[i][3]==0&&a[i][4]==0) kol34++;
        }
        for (int i=1; i<=n; i++)
        {
            if (a[i][1]==0&&a[i][2]==0&&a[i][3]==0&&kol4>0) {cout<<"YES"<<endl; return 0;}
            if (a[i][1]==0&&a[i][2]==0&&a[i][4]==0&&kol3>0) {cout<<"YES"<<endl; return 0;}
            if (a[i][1]==0&&a[i][3]==0&&a[i][4]==0&&kol2>0) {cout<<"YES"<<endl; return 0;}
            if (a[i][2]==0&&a[i][3]==0&&a[i][4]==0&&kol1>0) {cout<<"YES"<<endl; return 0;}
        }
        if (kol12>0&&kol34>0) {cout<<"YES"<<endl; return 0;}
        if (kol13>0&&kol24>0) {cout<<"YES"<<endl; return 0;}
        if (kol14>0&&kol23>0) {cout<<"YES"<<endl; return 0;}
        cout<<"NO"<<endl;
    }
}