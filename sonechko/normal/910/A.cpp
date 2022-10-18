#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    a="."+a;
    int pos=1;
    int kol=0;
    while (pos!=n)
    {
        kol++;
        for (int j=m; j>=1; j--)
        if (pos+j<=n&&a[pos+j]=='1') {pos+=j; break;}
        if (kol==n*2) {cout<<"-1"<<endl; return 0;}
    }
    cout<<kol<<endl;
}