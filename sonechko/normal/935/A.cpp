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
         int ans=0;
         for (int i=1; i<n; i++)
         if ((n-i)%i==0) ans++;
         cout<<ans<<endl;
}