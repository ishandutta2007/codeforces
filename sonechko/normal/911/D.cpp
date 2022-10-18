#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
         int n;
         cin>>n;
         for (int i=1; i<=n; i++)
         cin>>a[i];
         int kol=0;
         for (int i=1; i<=n; i++)
         for (int j=i+1; j<=n; j++)
         if (a[i]>a[j]) kol++;
         int m;
         cin>>m;
         kol%=2;
         for (int p=1; p<=m; p++)
         {
                   int l,r;
                   cin>>l>>r;
                   if ((r-l+1)/2%2==1) kol^=1;
                   if (kol==0) cout<<"even"<<"\n"; else cout<<"odd"<<"\n";
         }
}