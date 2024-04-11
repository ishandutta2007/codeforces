#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y,a,b,kol=0;
    cin>>x>>y>>a>>b;
    for (int i=a; i<=x; i++)
    for (int j=b; j<min(y+1,i); j++)
    kol++;
    cout<<kol<<endl;
    for (int i=a; i<=x; i++)
    for (int j=b; j<min(y+1,i); j++)
    cout<<i<<" "<<j<<endl;
}