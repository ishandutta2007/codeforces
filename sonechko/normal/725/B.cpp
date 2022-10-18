#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 200000+10;
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
#define y1 dbfuebfwkjNSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
int use[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    ll n;
    cin>>n;
    char ch;
    cin>>ch;
    ll ans=0;
    if (n%4==0)
    {
        ans=(n-3)+6+((n-1)/4*12);
    }
    if (n%4==3)
    {
        ans=(n/4*12)+(n-3);
    }
    if (n%4==2)
    {
        ans=(n-1)+6+((n-1)/4*12);
    }
    if (n%4==1)
    {
        ans=(n-1)+((n-1)/4*12);
    }
    if (ch=='f') ans++;
    if (ch=='e') ans+=2;
    if (ch=='d') ans+=3;
    if (ch=='a') ans+=4;
    if (ch=='b') ans+=5;
    if (ch=='c') ans+=6;

    cout<<ans<<endl;
}