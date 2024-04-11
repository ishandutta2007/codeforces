#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000+10;
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
#define next ifhiuebf
#define last dkbffjrb
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    string s;
    cin>>s;
    int k=-1;
    for (int i=0; i<s.size(); i++)
    if (s[i]!='a') {k=i; break;}
    if (k==-1) {s[s.size()-1]='z'; cout<<s<<endl; return 0;}
    for (int i=k; i<s.size(); i++)
    if (s[i]!='a') {s[i]=s1[s[i]-'a'-1];} else break;
    cout<<s<<endl;
}