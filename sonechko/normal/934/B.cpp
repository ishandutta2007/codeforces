#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n==1) {cout<<6<<endl; return 0;}
    int d=n/2;
    int p=n%2;
    if (d+p<=18)
    {
              for (int i=1; i<=d; i++)
              cout<<8;
              for (int i=1; i<=p; i++)
              cout<<0;
              return 0;
    }
    cout<<-1<<endl;
}