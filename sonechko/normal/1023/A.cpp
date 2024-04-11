#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 1e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    s="."+s;
    t="."+t;
    int pos=0;
    for (int i=1; i<=n; i++)
        if (s[i]=='*') pos=i;
    if (pos==0)
    {
        if (s==t) {cout<<"YES"<<endl; return 0;}
        cout<<"NO"<<endl;
        return 0;
    }
    if (n-1>m) {cout<<"NO"<<endl; return 0;}
    for (int i=1; i<pos; i++)
    if (s[i]!=t[i]) {cout<<"NO"<<endl; return 0;}
    int c=m+1;
    for (int i=n; i>pos; i--)
    {
        c--;
        if (s[i]!=t[c]) {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
}