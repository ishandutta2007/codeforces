#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e2 + 11;
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    if (n<=2) cout<<-1<<endl; else
    if (n%2==1) cout<<(n+1)*(n/2)<<" "<<(n+1)*(n/2)+1<<endl; else
    if (n==4) cout<<3<<" "<<5<<endl; else
    if ((n/2)%2==1) cout<<(n+2)*(n/4)<<" "<<(n+2)*(n/4)+2<<endl; else
    cout<<(n+2)*(n/4)-n/2-1<<" "<<(n+2)*(n/4)-n/2+1<<endl;
}