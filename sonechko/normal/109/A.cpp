#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e2 + 11;
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol=n+1,p1=n,p2=n;
    for (int p=0; p<=n; p++)
        if (4*p<=n&&(n-4*p)%7==0&&4*p+(n-4*p)/7<=kol)
    {
        kol=4*p+(n-4*p)/7;
        p1=p;
        p2=(n-4*p)/7;
    }
    if (kol==n+1) cout<<-1<<endl; else
    {
        for (int i=1; i<=p1; i++)
            cout<<4;
        for (int i=1; i<=p2; i++)
            cout<<7;
    }
}