#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
int a[10],b[10],c[10];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        a[ch-'0']++;
    }
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        b[ch-'0']++;
        c[ch-'0']++;
    }
    int kol1=0,kol2=0;
    for (int i=0; i<=9; i++)
    for (int p=1; p<=a[i]; p++)
    {
        int d=0;
        for (int j=i; j<=9; j++)
        if (b[j]>0) {b[j]--; d=1; break;}
        if (d==0)
        {
            kol1++;
            for (int j=0; j<=9; j++)
            if (b[j]>0) {b[j]--; break;}
        }

        d=0;
        for (int j=i+1; j<=9; j++)
        if (c[j]>0) {c[j]--; d=1; break;}
        if (d==1) kol2++;
        if (d==0)
        {
            for (int j=0; j<=9; j++)
            if (c[j]>0) {c[j]--; break;}
        }
    }
    cout<<kol1<<endl<<kol2<<endl;
}