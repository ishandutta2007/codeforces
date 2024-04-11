#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next ljjdfienf
char b[N];
int a[N];
int main()
{
    string s;
    getline(cin,s);
    int n=0,k=0;
    for (int i=0; i<s.size(); i++)
    if (s[i]>='0'&&s[i]<='9') {k=k*10+(s[i]-'0');} else
    if (s[i]=='?') n++; else
    if (s[i]=='+'||s[i]=='-') b[n]=s[i];
    a[1]=k;
    int k1=0;
    for (int i=1; i<n; i++)
        {
            if (b[i]=='+') k1++; else k1--;
            a[i+1]=1;
        }
    int p=k+k1;
    for (int i=1; i<n; i++)
        if (b[i]=='+'&&k>p)
            {int h=min(k-p,k-a[i+1]); p+=h; a[i+1]+=h;}
    for (int i=0; i<n; i++)
    if ((b[i]=='-')&&k<p)
        {int h=min(p-k,k-a[i+1]); p-=h; a[i+1]+=h;}
    if (k<p) {int h=min(p-k,a[1]-1); p-=h; a[1]-=h;}
    int t=a[1];
    for (int i=1; i<n; i++)
        if (b[i]=='-') t-=a[i+1]; else t+=a[i+1];
    if (t!=k) {cout<<"Impossible"<<endl; return 0;}
    cout<<"Possible"<<endl;
    cout<<a[1]<<" ";
    for (int i=1; i<n; i++)
        cout<<b[i]<<" "<<a[i+1]<<" ";
    cout<<"= "<<k<<endl;
}