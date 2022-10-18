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
          int n;
          cin>>n;
          for (int i=1; i<=n; i++)
          cin>>a[i];
          for (int i=1; i<=n; i++)
          {
                    int d=a[i];
                    int p=a[d];
                    if (a[p]==i) {cout<<"YES"<<endl; return 0;}
          }
          cout<<"NO"<<endl;
}