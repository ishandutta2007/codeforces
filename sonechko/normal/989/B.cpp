#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s="_"+s;
    int dk=0;
    for (int i=1; i<=n-m; i++)
    if (s[i]=='.'&&s[i+m]=='.') {s[i]='1'; s[i+m]='0'; dk=1; break;} else
    if (s[i]=='.'&&s[i+m]=='1') {s[i]='0'; dk=1; break;} else
    if (s[i]=='.'&&s[i+m]=='0') {s[i]='1'; dk=1; break;} else
    if (s[i]=='1'&&s[i+m]=='0') {dk=1; break;} else
    if (s[i]=='1'&&s[i+m]=='.') {s[i+m]='0'; dk=1; break;} else
    if (s[i]=='0'&&s[i+m]=='.') {s[i+m]='1'; dk=1; break;} else
    if (s[i]=='0'&&s[i+m]=='1') {dk=1; break;}
    if (dk==0) {cout<<"No"<<endl; return 0;}
    for (int j=1; j<=n; j++)
        if (s[j]=='.') cout<<'1'; else cout<<s[j];
}