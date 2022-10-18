#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000002;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next aihfuebf
int ans[5001],a[5001],num[5001];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            num[j]=0;
        num[0]=0;
        int res=0;
        for (int j=i; j<=n; j++)
        {
            num[a[j]]++;
            if ((num[a[j]]>num[res])||(num[a[j]]==num[res]&&a[j]<res)) res=a[j];
            ans[res]++;
        }
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}