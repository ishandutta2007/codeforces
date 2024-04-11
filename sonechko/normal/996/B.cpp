#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol=1e9;
    for (int i=0; i<n; i++)
    {
          cin>>a[i];
          kol=min(kol,a[i]);
    }
    int pos=kol%n;
    while (a[pos]>kol)
    {
          pos=(pos+1)%n;
          kol++;
    }
    cout<<pos+1<<endl;
}