#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1000 + 11;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=2*n; i++)
        cin>>a[i];
    sort(a+1,a+2*n+1);
    if (a[n]!=a[n+1]) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}