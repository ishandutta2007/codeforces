#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100002;
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
#define next ljjdfienf
int a[10005];
string b[10005][4];
set <string> st;
//t[10001],x[10001],y[10001],z[10001],b[10001],c[10001];
int main()
{
    string s;
    cin>>s;
    if (s.size()<=6) {cout<<0<<endl; return 0;}
    string t="";
    for (int i=5; i<s.size(); i++)
        t+=s[i];
    for (int i=0; i<t.size()-1; i++)
        {
            b[i][2]=t[i];
            b[i][2]+=t[i+1];
        }
    for (int i=0; i<t.size()-2; i++)
        {
        b[i][3]=t[i];
        b[i][3]+=t[i+1];
        b[i][3]+=t[i+2];
        }
    a[t.size()]=1;
    if (t.size()>1)
    {
        a[t.size()-2]=1; st.insert(b[t.size()-2][2]);
    }
    if (t.size()>2)
    {
        a[t.size()-3]=1; st.insert(b[t.size()-3][3]);
    }
    for (int i=t.size()-4; i>=0; i--)
    {
        s=b[i][2];
        if (((a[i+5])||(a[i+4]&&s!=b[i+2][2]))
             &&a[i+2])
            {a[i]=1; st.insert(s);}
        s=b[i][3];
        if (((a[i+5])||(a[i+6]&&s!=b[i+3][3]))
             &&a[i+3])
            {a[i]=1; st.insert(s);}
    }
    cout<<st.size()<<endl;
    while (!st.empty())
    {
        cout<<*st.begin()<<endl;
        st.erase(*st.begin());
    }
}