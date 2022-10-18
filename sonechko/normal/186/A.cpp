#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 10000000 + 11;
int a[N];
int main()
{
    string s,t;
    cin>>s>>t;
    int k=0,p1=0,p2=0;
    if (s.size()!=t.size()) {cout<<"NO"<<endl; return 0;}
    for (int i=0; i<t.size(); i++)
        if (t[i]!=s[i]) {k++; if (k==1) p1=i; if (k==2) p2=i;}
    if (k==0) cout<<"YES"<<endl; else
    if (k==2)
    {
        swap(s[p1],s[p2]);
        if (s==t) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    } else cout<<"NO"<<endl;
}