#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sum=0;
    for (int i=1; i<=6; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1; i<=6; i++)
    for (int j=i+1; j<=6; j++)
    for (int k=j+1; k<=6; k++)
    if (a[i]+a[j]+a[k]==sum-a[i]-a[j]-a[k])
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}
//