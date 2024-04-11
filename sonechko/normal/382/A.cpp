#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 105;
const int M = 10;
const string charA = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string chara = ".abcdefghijklmnopqrstuvwxyz";
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
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string t1="",t2="";
    int k=0;
    for (int i=0; i<s1.size(); i++)
        if (k==0&&s1[i]=='|') k=1; else
        if (k==0) t1+=s1[i]; else t2+=s1[i];
    for (int i=0; i<s2.size(); i++)
        if (t1.size()<=t2.size()) t1+=s2[i]; else t2+=s2[i];
    if (t1.size()!=t2.size()) cout<<"Impossible"<<endl; else
        cout<<t1<<"|"<<t2<<endl;
}