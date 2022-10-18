#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 200000+10;
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
int a[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int ans=0,p=0;
    for (int i=1; i<=n; i++)
        if (a[i]%2==1)
        {
            if (p==1) p=0; else
                p=1;
        } else
        if (p==1)
        {
            if (a[i]==0) {cout<<"NO"<<endl;
            return 0;}
        }
    if (p==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}