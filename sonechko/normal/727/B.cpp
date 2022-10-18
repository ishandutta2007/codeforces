#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 1000+10;
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
string d[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    string s;
    getline(cin,s);
    s='.'+s;
    int k=0,h=0;
    for (int i=1; i<s.size(); i++)
    if ((s[i]>='0'&&s[i]<='9')||s[i]=='.')
    {
        if (h==0) {k++;}
        h=1;
        d[k]=d[k]+s[i];
    } else h=0;
    int f1=0,g1=0;
    for (int i=1; i<=k; i++)
    {
        string t=d[i];
        t='-'+t;
        int p=t.size();
        for (int i=t.size()-1; i>=1; i--)
        if (t[i]=='.') {p=i; break;}
        if (p!=t.size()-1-2) p=t.size();
        int f=0, g=0;
        for (int i=1; i<p; i++)
            if (t[i]!='.') f=f*10+(t[i]-'0');
        for (int i=p+1; i<t.size(); i++)
        g=g*10+(t[i]-'0');
        f1+=f;
        g1+=g;
    }
    f1+=g1/100;
    g1=g1%100;
    if (f1>999999)
    {
        cout<<f1/1000000<<".";
        f1%=1000000;
        if (f1/1000<10) cout<<"00"<<f1/1000; else
            if (f1/1000<100) cout<<"0"<<f1/1000; else
            cout<<f1/1000;
        cout<<".";
         if (f1%1000<10) cout<<"00"<<f1%1000; else
            if (f1%1000<100) cout<<"0"<<f1%1000; else
            cout<<f1%1000;
    } else
    if (f1>999) {
            cout<<f1/1000<<".";
            if (f1%1000<10) cout<<"00"<<f1%1000; else
            if (f1%1000<100) cout<<"0"<<f1%1000; else
            cout<<f1%1000;
    } else
    cout<<f1;
    if (g1==0) cout<<endl; else
    if (g1<10) cout<<".0"<<g1<<endl; else
    cout<<"."<<g1<<endl;
}