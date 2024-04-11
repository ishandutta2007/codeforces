#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 1000000+10;
const int M = 1000;
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
pair<int,int> a[N];
int b[N];
string ans[N],da[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    cin>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6];
    int n;
    cin>>n;
    da[1]="S";
    da[2]="M";
    da[3]="L";
    da[4]="XL";
    da[5]="XXL";
    da[6]="XXXL";
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        if (s=="S") a[i]=mp(1,0); else
        if (s=="M") a[i]=mp(2,0); else
        if (s=="L") a[i]=mp(3,0); else
        if (s=="XL") a[i]=mp(4,0); else
        if (s=="XXL") a[i]=mp(5,0); else
        if (s=="XXXL") a[i]=mp(6,0); else
        if (s[0]=='S') a[i]=mp(1,1); else
        if (s[0]=='M') a[i]=mp(2,1); else
        if (s[0]=='L') a[i]=mp(3,1); else
        if (s[1]=='L') a[i]=mp(4,1); else
        if (s[2]=='L') a[i]=mp(5,1); else
        a[i]=mp(6,1);
    }
    for (int i=1; i<=n; i++)
        if (a[i].s==0)
    {
        if (b[a[i].f]!=0)
            {ans[i]=da[a[i].f]; b[a[i].f]--;}
    }
    for (int i=1; i<=6; i++)
        {
            for (int j=1; j<=n; j++)
        if (ans[j]==""&&a[j].s==1)
    {
        if (a[j].f+1==i&&b[i]>0)
        {
            b[i]--;
            ans[j]=da[i];
        }
    }
    for (int j=1; j<=n; j++)
        if (ans[j]==""&&a[j].s==1)
    {
        if (a[j].f==i&&b[i]>0)
        {
            b[i]--;
            ans[j]=da[i];
        }
    }
        }
    for (int i=1; i<=n; i++)
    if (ans[i]=="") {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<endl;
}