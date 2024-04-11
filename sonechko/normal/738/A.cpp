#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 200000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+5;
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
#define y1 dbfuebfwkmjjzdbhqfja
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
#define left second
#define pii pair<ll,ll>
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+="...";
    int k=0;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='g'&&s[i+1]=='o'&&k==1)
        {
        } else
        if (k==1&&s[i]=='o'&&s[i-1]=='g')
        {

        } else
        if (s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
        {
            cout<<"***";
            k=1;
        } else
        {
            cout<<s[i];
            k=0;
        }
    }
    cout<<endl;
}