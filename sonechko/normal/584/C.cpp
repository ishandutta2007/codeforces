#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;
char g(char a, char b)
{
    if (a!='a'&&b!='a') return 'a';
    if (a!='b'&&b!='b') return 'b';
    return 'c';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    m=n-m;
    string s,t;
    cin>>s>>t;

    int kol=0;
    for (int i=0; i<n; i++)
    if (s[i]==t[i]) kol++;
    if (kol>=m)
    {
        for (int i=0; i<n; i++)
        if (s[i]==t[i]&&m>0) {cout<<s[i]; m--;} else
            cout<<g(s[i],t[i]);
        return 0;
    }
    int kk1=m-kol,kk2=m-kol;
    if (kk1+kk2+kol>n) {cout<<-1<<endl; return 0;}
    for (int i=0; i<n; i++)
        if (s[i]==t[i]&&m>0) {cout<<s[i];} else
        if (kk1>0) {cout<<s[i]; kk1--;} else
        if (kk2>0) {cout<<t[i]; kk2--;} else cout<<g(s[i],t[i]);
}