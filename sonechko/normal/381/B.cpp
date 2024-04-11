#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 1000000+10;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
ll use[N],b[N];
int f(int l)
{
    if (l==0) return 0;
    if (l%2==0) return f(l/2);
    return f(l/2)+1;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        use[l]++;
    }
    int ans=0;
    for (int i=1; i<=5000; i++)
        if (use[i]>0)
    {
        ans++;
        b[ans]=i;
        use[i]--;
    }
    for (int i=5000; i>=1; i--)
    if (use[i]>0&&i<b[ans]){
    ans++;
    b[ans]=i;
    }
    cout<<ans<<endl;
    for (int i=1; i<=ans; i++)
        cout<<b[i]<<" ";
    cout<<endl;
}