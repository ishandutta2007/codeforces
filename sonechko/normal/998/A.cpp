#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
#define mod %MOD

const int N = 1e6 + 11;
const ll MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int pos=1;
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<a[pos]) pos=i;
        sum+=a[i];
    }
    if (n==1||sum-a[pos]==a[pos]) cout<<-1<<endl; else
    {
        cout<<1<<endl;
        cout<<pos<<endl;
    }
}