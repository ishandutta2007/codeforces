#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
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
#define next ifhiuebf1
#define last dkbffjrb
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    int l,r;
    char ch;
    cin>>l>>ch>>r;
    if (n==24)
    {
        if (l>=24)
            cout<<0<<l%10<<ch; else
        if (l<10) cout<<0<<l<<ch; else
        cout<<l<<ch;
    } else
    {
        if (l==0)
            cout<<0<<1<<ch; else
        if (l>12)
        {
            if (l%10==0)
                cout<<10<<ch;
            else
            cout<<0<<l%10<<ch;
        } else
        if (l<10) cout<<0<<l<<ch; else
            cout<<l<<ch;
    }
    if (r<10) cout<<0<<r; else
    if (r<=59) cout<<r; else
    cout<<0<<r%10;
    cout<<endl;
}