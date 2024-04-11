#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 2000000+10;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define se second
#define ll long long
#define fi first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int t1[N], t[N], c[N], b[N], a[N];
pair<int,pair<int,int> >h[N];
int n;
void update(int l, int k)
{

    for (int i=l; i<=n; i|=i+1)
    t[i]^=k;
}
int sum(int l)
{
    int ans=0;
    for (int i=l; i>=0; i&=(i+1), i--)
    ans^=t[i];
    return ans;
}
int sum(int l, int r)
{
    return sum(r)^sum(l-1);
}
void update1(int l, int k)
{
    for (int i=l; i<=n; i|=i+1)
    t1[i]^=k;
}
int sum1(int l)
{
    int ans=0;
    for (int i=l; i>=0; i&=(i+1), i--)
    ans^=t1[i];
    return ans;
}
int sum1(int l, int r)
{
    return sum1(r)^sum1(l-1);
}
map<int,int> mt,use;
int tim[N];
int ans[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            update(i,a[i]);
        }
    int m;
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &b[i], &c[i]);
        ans[i]=sum(b[i],c[i]);
        h[i]=mp(b[i],mp(c[i],i));
    }
    sort(h+1,h+m+1);
    for (int i=1; i<=n; i++)
        {
            //out<<a[i]<<endl;
            if (use[a[i]]==0) {update1(i,a[i]);}
            use[a[i]]=1;
            //update(i+1,a[i]);
        }
    int k=0;
    for (int i=1; i<=n; i++)
    {
        tim[mt[a[i]]]=i;
        mt[a[i]]=i;
    }
    for (int i=1; i<=n; i++)
    {
        if (k==m) break;
        while (h[k+1].fi==i)
        {
            k++;
            ans[h[k].se.se]^=sum1(h[k].fi,h[k].se.fi);
            if (k==m) break;
        }
        update1(i,a[i]);
        update1(tim[i],a[i]);
    }
    for (int i=1; i<=m; i++)
        printf("%d\n", ans[i]);
}