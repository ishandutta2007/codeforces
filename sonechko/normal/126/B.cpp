#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 1000000+10;
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
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int z[N],maxi[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    string s;
    cin>>s;
    int l=0,r=0;
    for (int i=1; i<s.size(); i++)
    {
        if (i<=r)
            z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<s.size()&&s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if (i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    int n=s.size()-1;
    for (int i=1; i<=n; i++)
        maxi[i]=max(maxi[i-1],z[i]);
    int ans=0;
    for (int i=n; i>=1; i--)
    if (i+z[i]-1==n)
    {
        int k=maxi[i-1];
    if (k>=z[i]) ans=max(ans,z[i]);
    }
    if (ans==0)
        cout<<"Just a legend";
    else
    for (int i=0; i<ans; i++)
    cout<<s[i];
    cout<<endl;
}