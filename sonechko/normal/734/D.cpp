#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+10;
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
int b1,b2,b3,b4,b5,b6,b7,b8;
int a1,a2,a3,a4,a5,a6,a7,a8;
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    b1=b2=b3=b4=b5=b6=b7=b8=INT_MAX;
    a1=a2=a3=a4=a5=a6=a7=a8=0;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        int l,r;
        cin>>l>>r;
            if (l==x)
            {
                if (r<y)
                {
                    if (y-r<b7)
                    {
                        b7=y-r;
                        a7=(ch=='Q'||ch=='R');
                    }
                }
                if (r>y)
                {
                    if (r-y<b3)
                    {
                    b3=r-y;
                    a3=(ch=='Q'||ch=='R');
                    }
                }
            }
            if (r==y)
            {
                if (l<x&&x-l<b1)
                {
                    b1=x-l;
                    a1=(ch=='Q'||ch=='R');
                }
                if (l>x&&l-x<b5)
                {
                    b5=l-x;
                    a5=(ch=='Q'||ch=='R');
                }
            }
            if (l+r==x+y)
            {
                if (r<y&&y-r<b2)
                {
                    b2=y-r;
                    a2=(ch=='Q'||ch=='B');
                }
                if (r>y&&r-y<b6)
                {
                    b6=r-y;
                    a6=(ch=='Q'||ch=='B');
                }
            }
            if (x-y==l-r)
            {
                if (l>x&&l-x<b4)
                {
                    b4=l-x;
                    a4=(ch=='Q'||ch=='B');
                }
                if (l<x&&x-l<b8)
                {
                    b8=x-l;
                    a8=(ch=='Q'||ch=='B');
                }
            }
    }

    if (a1+a2+a3+a4+a5+a6+a7+a8>0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}