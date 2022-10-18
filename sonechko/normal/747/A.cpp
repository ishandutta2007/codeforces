#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define tab difjke
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAl
    int n;
    cin>>n;
    int ans=INT_MAX,l=0,r=0;
    for (int i=1; i<=n; i++)
        if (n%i==0&&n/i>=i&&abs(n/i-i)<ans)
        {
            ans=abs(n/i-i);
            l=i;
            r=n/i;
        }
    cout<<l<<" "<<r<<endl;
}