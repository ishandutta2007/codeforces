#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 5000+5;
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
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
int a[N];
int main()
{
    /**
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n==1)
    {
        if (a[1]==0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
        return 0;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (a[i]==0) ans++;
    if (ans==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    **/
    string s;
    cin>>s;
    int n=s.size();
    s='1'+s;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='A'||s[i]=='H'||s[i]=='I'||s[i]=='M'||s[i]=='O'||s[i]=='o'||s[i]=='T'||s[i]=='U'||s[i]=='W'||s[i]=='w'||s[i]=='V'||s[i]=='v'||s[i]=='X'||s[i]=='x'||s[i]=='Y')
        {
            if (s[i]!=s[n-i+1]) {cout<<"NIE"<<endl; return 0;}
        } else
        if (s[i]=='b')
        {
            if (s[n-i+1]!='d') {cout<<"NIE"<<endl; return 0;}
        } else
        if (s[i]=='d')
        {
            if (s[n-i+1]!='b') {cout<<"NIE"<<endl; return 0;}
        } else
        if (s[i]=='p')
        {
            if (s[n-i+1]!='q') {cout<<"NIE"<<endl; return 0;}
        } else
        if (s[i]=='q')
        {
            if (s[n-i+1]!='p') {cout<<"NIE"<<endl; return 0;}
        } else {cout<<"NIE"<<endl; return 0;}
    }
    cout<<"TAK"<<endl;
}