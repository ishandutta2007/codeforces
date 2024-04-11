#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000+7;
const int N = 200000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+15;
const int N6 = 1000000+5;
const int N7 = 10000000+5;
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
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    string s;
    cin>>s;
    s='.'+s;
    int k=0,ans=0;
    for (int i=1; i<s.size(); i++)
        if (s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U'||s[i]=='Y')
    {
        ans=max(ans,i-k);
        k=i;
    }
    ans=max(ans,(int)s.size()-k);
    cout<<ans<<endl;
}