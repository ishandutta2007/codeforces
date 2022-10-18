#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long



const ll N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int mini=INT_MAX,kol=0;
    for (int i=2; i<=n; i++)
    if (a[i]-a[i-1]<mini) {mini=a[i]-a[i-1]; kol=1;} else
    if (a[i]-a[i-1]==mini) kol++;
    cout<<mini<<" "<<kol<<endl;
}