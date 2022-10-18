#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 1000+10;
const int M = 100;
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
int a[N][N],b[N][N],c[N][N],d[N][N],e[N][N],f[N][N];
char pref1[N][N], pref2[N][N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    pair<int,int> p=mp(0,0);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            int l;
            cin>>l;
            if (l==0) {p=mp(i,j);a[i][j]=1; b[i][j]=1;}
            while (l!=0&&l%2==0)
            {
                l/=2;
                a[i][j]++;
            }
            while (l!=0&&l%5==0)
            {
                l/=5;
                b[i][j]++;
            }
        }
    for (int i=1; i<=n; i++)
        {
            c[1][i]=a[1][i]+c[1][i-1];
            d[1][i]=b[1][i]+d[1][i-1];
            e[1][i]=c[1][i];
            f[1][i]=d[1][i];
        }
    for (int i=1; i<=n; i++)
    {
        c[i][1]=a[i][1]+c[i-1][1];
        d[i][1]=b[i][1]+d[i-1][1];
        e[i][1]=c[i][1];
        f[i][1]=d[i][1];
    }
    for (int i=2; i<=n; i++)
        for (int j=2; j<=n; j++)
        {
            if (c[i-1][j]<c[i][j-1]||(c[i-1][j]==c[i][j-1]&&d[i-1][j]<d[i][j-1]))
            {
                c[i][j]=c[i-1][j]+a[i][j];
                d[i][j]=d[i-1][j]+b[i][j];
                pref1[i][j]='D';
            } else
            {
                c[i][j]=c[i][j-1]+a[i][j];
                d[i][j]=d[i][j-1]+b[i][j];
                pref1[i][j]='R';
            }
            if (f[i-1][j]<f[i][j-1]||(f[i-1][j]==f[i][j-1]&&e[i-1][j]<e[i][j-1]))
            {
                f[i][j]=f[i-1][j]+b[i][j];
                e[i][j]=e[i-1][j]+a[i][j];
                pref2[i][j]='D';
            } else
            {
                f[i][j]=f[i][j-1]+b[i][j];
                e[i][j]=e[i][j-1]+a[i][j];
                pref2[i][j]='R';
            }
        }
    if (p!=mp(0,0)&&min(c[n][n],d[n][n])>1&&min(e[n][n],f[n][n])>1)
    {
        cout<<1<<endl;
        for (int i=2; i<=p.f; i++)
            cout<<'D';
        for (int j=2; j<=p.s; j++)
            cout<<'R';
        for (int i=p.f+1; i<=n; i++)
            cout<<'D';
        for (int i=p.s+1; i<=n; i++)
            cout<<'R';
        cout<<endl;
        return 0;
    }
    if (min(c[n][n],d[n][n])<min(e[n][n],f[n][n]))
    {
        cout<<min(c[n][n],d[n][n])<<endl;
        string t="";
        int l=n,r=n;
        while (1==1)
        {
            if (l==1&&r==1) break;
            if (l==1) {t+="R"; r--;} else
            if (r==1) {t+="D"; l--;} else
            {
                t=t+pref1[l][r];
                if (pref1[l][r]=='D') l--;
                else r--;
            }
        }
        for (int i=t.size()-1; i>=0; i--)
            cout<<t[i];
        cout<<endl;
    } else
    {
        cout<<min(e[n][n],f[n][n])<<endl;
        string t="";
        int l=n,r=n;
        while (1==1)
        {
            if (l==1&&r==1) break;
            if (l==1) {t+="R"; r--;} else
            if (r==1) {t+="D"; l--;} else
            {
                t=t+pref2[l][r];
                if (pref2[l][r]=='D') l--;
                else r--;
            }
        }
        for (int i=t.size()-1; i>=0; i--)
            cout<<t[i];
        cout<<endl;
    }
}