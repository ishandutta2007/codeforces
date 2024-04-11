#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e18;
#define mod %MOD
int a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=k; i++)
        cin>>b[i];
    sort(b+1,b+k+1);
    for (int i=1; i<=n; i++)
    if (a[i]==0) {a[i]=b[k]; k--;}
    for (int i=2; i<=n; i++)
    if (a[i]<a[i-1]) {cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl;
    return 0;

}