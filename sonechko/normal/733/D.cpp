#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000+7;
const int N = 100000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+15;
const int N6 = 1000000+5;
const int N7 = 10000000+5;
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
#define y1 dbfuebfwkjNSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
int a[N],b[N],c[N];
map<pair<int,int>, pair<int,int> > mt1,mt2;
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if (l>r) swap(l,r);
        if (r>k) swap(r,k);
        if (l>r) swap(l,r);
        a[i]=l;
        b[i]=r;
        c[i]=k;
        pair<int,int> p=mt1[mp(l,r)];
        if (p.f==0||k>p.f)
        {
            mt2[mp(l,r)]=p;
            mt1[mp(l,r)]=mp(k,i);
        } else
        {
        pair<int,int> p1=mt2[mp(l,r)];
        if (p1.f==0||k>p1.f) mt2[mp(l,r)]=mp(k,i);
        }

        if (mp(l,k)!=mp(l,r))
        {
        p=mt1[mp(l,k)];
        if (p.f==0||r>p.f)
        {
            mt2[mp(l,k)]=p;
            mt1[mp(l,k)]=mp(r,i);
        } else
        {
        pair<int,int> p1=mt2[mp(l,k)];
        if (p1.f==0||r>p1.f) mt2[mp(l,k)]=mp(r,i);
        }
        }

        if (mp(l,r)!=mp(r,k)&&mp(l,k)!=mp(r,k))
        {
        p=mt1[mp(r,k)];
        if (p.f==0||l>p.f)
        {
            mt2[mp(r,k)]=p;
            mt1[mp(r,k)]=mp(l,i);
        } else
        {
        pair<int,int> p1=mt2[mp(r,k)];
        if (p1.f==0||l>p1.f) mt2[mp(r,k)]=mp(l,i);
        }
        }
    }
    int ans=0,res=0,k1=0,k2=0;
    for (int i=1; i<=n; i++)
    {
        pair<int,int> p1=mt1[mp(b[i],c[i])],p2=mt2[mp(b[i],c[i])];
        if (p1.s!=i&&p1.s!=0)
        {
            int k=a[i]+p1.f;
            if (min(k,min(b[i],c[i]))>ans)
            {
                res=2;
                k1=i;
                k2=p1.s;
                ans=min(k,min(b[i],c[i]));
            }
        }
        p1=p2;
        if (p1.s!=i&&p1.s!=0)
        {
            int k=a[i]+p1.f;
            if (min(k,min(b[i],c[i]))>ans)
            {
                res=2;
                k1=i;
                k2=p1.s;
                ans=min(k,min(b[i],c[i]));
            }
        }
        if (a[i]>ans)
        {
            res=1;
            k1=i;
            ans=a[i];
        }
    }
    cout<<res<<endl;
    if (res==1) cout<<k1<<endl;
    else cout<<k1<<" "<<k2<<endl;
}