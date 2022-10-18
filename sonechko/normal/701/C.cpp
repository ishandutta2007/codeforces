#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 3000000+5;
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
map<char,int> mt, mh;
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
#endif
sync;
string s;
int n;
cin>>n;
cin>>s;
s='.'+s;
int k=0;
int ans=INT_MAX;
for (int i=1; i<=n; i++)
{
    if (mt[s[i]]==0) {mt[s[i]]=1; k++;}
}
int d=0, l=1;
for (int i=1; i<=n; i++)
{
    if (mh[s[i]]==0) {d++; mh[s[i]]=1;} else mh[s[i]]++;
    while (mh[s[l]]>1)
    {
        mh[s[l]]--;
        l++;
    }
    if (d==k) ans=min(ans,i-l+1);
}
cout<<ans<<endl;
}