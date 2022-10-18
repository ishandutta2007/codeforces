#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
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
    int n,k;
    cin>>n>>k;
    int p=240,t=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        t+=5*i;
        if (t+k<=p) ans=i; else break;
    }
    cout<<ans<<endl;
}