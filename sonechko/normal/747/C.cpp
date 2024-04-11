#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
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
    #endif // LOCAl
    int n,m;
    cin>>n>>m;
    for (int j=1; j<=m; j++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int ans=0,ans1=0;
        for (int i=1; i<=n; i++)
        if (a[i]<l) {ans1+=i; ans++; if (ans==r) break;}
        if (ans<r)
            {cout<<-1<<endl;} else
            {
                cout<<ans1<<endl;
                for (int i=1; i<=n; i++)
                    if (a[i]<l)
                {a[i]=l+k-1;
                r--;
                if (r==0) break;
                }
            }
    }
}