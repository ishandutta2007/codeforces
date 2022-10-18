#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 100000 + 11;
int a[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[n]<<" ";
    for (int i=2; i<n; i++)
        cout<<a[i]<<" ";
    cout<<a[1]<<endl;
}