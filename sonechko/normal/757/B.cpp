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
int a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        int d=2;
        while (d*d<=l)
        {
            if (l%d==0)
            {
                a[d]++;
                while (l%d==0)
                    l/=d;
            }
            d++;
        }
        a[l]++;
    }
    int ans=1;
    for (int i=2; i<=100000; i++)
        ans=max(ans,a[i]);
    cout<<ans<<endl;
}