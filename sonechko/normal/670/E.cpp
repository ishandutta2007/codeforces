#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000002;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
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
#define next aihfuebf
int par[N],next[N],last[N],b[N];
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    string s;
    cin>>s;
    s='1'+s;
    int k=0;
    for (int i=1; i<=n; i++)
    if (s[i]=='(') {k++; b[k]=i;} else {par[i]=b[k]; par[b[k]]=i; k--;}
    for (int i=1; i<=n; i++)
    {
        next[i]=i+1;
        last[i]=i-1;
    }
    next[n]=0;
    int t=1;
    for (int i=1; i<=m; i++)
    {
        char ch;
        cin>>ch;
        //cout<<p<<endl;
        if (ch=='R') p=next[p]; else
        if (ch=='L') p=last[p]; else
        {
            int l=min(p,par[p]);
            int r=max(p,par[p]);
            //cout<<l<<" "<<r<<endl;
            next[last[l]]=next[r];
            last[next[r]]=last[l];
            if (l==t) t=next[r];
            if (next[r]==0) p=last[l]; else p=next[r];
        }
    }
    while (1==1)
    {
        cout<<s[t];
        if (next[t]==0) return 0;
        t=next[t];
    }
    cout<<endl;
}