#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100000+10;
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
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    ll a00,a01,a10,a11;
    cin>>a00>>a01>>a10>>a11;
    ll zero=1, one=1, ch0=0, ch1=0;
    if (a00==0&&a01==0&&a10==0)
    {
        zero=0;
    }
    if (a11==0&&a01==0&&a10==0)
    {
        one=0;
    }
    for (int i=1; i<=1000000; i++)
    {
        if (i<=a00) {a00-=i; zero++;}
        if (i<=a11) {a11-=i; one++;}
    }
    if (a00!=0||a11!=0) {cout<<"Impossible"<<endl; return 0;}
    if ((zero+one)*(zero+one-1)/2!=zero*(zero-1)/2+a01+a10+one*(one-1)/2)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    string s="";
    for (int i=1; i<=one; i++)
    if (a10>=zero) {a10-=zero; s+="1";} else
    {
        while (a10<zero)
        {
        zero--;
        s+="0";
        }
        a10-=zero;
        s+="1";
    }
    for (int i=1; i<=zero; i++)
        s+="0";
    if (a10==0&&a01==0&&zero==0&&one==0)
        cout<<0<<endl; else
        cout<<s<<endl;
}