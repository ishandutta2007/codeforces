#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define tab difjke
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAl
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n%4!=0) {cout<<"==="<<endl; return 0;}
    int p=n/4,a=0,b=0,c=0,d=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='A') a++; else
        if (s[i]=='G') b++; else
        if (s[i]=='C') c++; else
        if (s[i]=='T') d++;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='?')
    {
        if (a<p) {a++; s[i]='A';} else
        if (b<p) {b++; s[i]='G';} else
        if (c<p) {c++; s[i]='C';} else {d++; s[i]='T';}
    }
    if (a==p&&b==p&&c==p&&d==p)
    {
        cout<<s<<endl;
    } else cout<<"==="<<endl;
}