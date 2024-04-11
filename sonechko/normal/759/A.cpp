#include<bits/stdc++.h>
using namespace std;
const int N = 3e5
 + 11;
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
#define ld long double
int a[N],b[N],use[N];
void rec(int l)
{
    use[l]=1;
    if (use[a[l]]==0) rec(a[l]);
    if (use[b[l]]==0) rec(b[l]);
}
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[a[i]]=i;
        }
    int l=0;
    for (int i=1; i<=n; i++)
    {
        int r;
        cin>>r;
        l+=r;
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0) {ans++; rec(i);}
    if (ans==1) ans=0;
    ans+=1-l%2;
    cout<<ans<<endl;
}