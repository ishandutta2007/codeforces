#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
bool prost(int n)
{
    if (n==1) return 0;
    for (int i=2; i<=(int)sqrt(n); i++)
        if (n%i==0) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (prost(n)) {cout<<1<<endl<<n<<endl; return 0;}
    if (prost(n-2)) {cout<<2<<endl<<2<<" "<<n-2<<endl; return 0;}
    int ans1=0;
    for (int i=n; i>=1; i--)
    if (prost(i)) {ans1=i; break;}
    n-=ans1;
    for (int i=n; i>=1; i--)
    if (prost(i)&&prost(n-i)) {cout<<3<<endl<<n-i<<" "<<i<<" "<<ans1<<endl; return 0;}
}