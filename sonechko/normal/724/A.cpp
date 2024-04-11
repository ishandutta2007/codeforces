#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
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
#define next ifhiuebf1
#define last dkbffjrb
int a[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    string s;
    cin>>s;
    int l=0;
    if (s[0]=='m') l=1; else
    if (s[0]=='t'&&s[1]=='u') l=2; else
    if (s[0]=='w') l=3; else
    if (s[0]=='t') l=4; else
    if (s[0]=='f') l=5; else
    if (s[1]=='a') l=6; else
    l=7;
    l--;
    int r=l;
    cin>>s;
    if (s[0]=='m') l=1; else
    if (s[0]=='t'&&s[1]=='u') l=2; else
    if (s[0]=='w') l=3; else
    if (s[0]=='t') l=4; else
    if (s[0]=='f') l=5; else
    if (s[1]=='a') l=6; else
    l=7;
    l--;
    if ((r+31)%7==l
      ||(r+30)%7==l
    || (r+28)%7==l)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}