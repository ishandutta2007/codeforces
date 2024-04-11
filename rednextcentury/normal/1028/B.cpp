#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
char a[1000][1000];
int main ()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string a="";
    while(n>0)
    {
        n-=4;
        a+="4";
    }
    a+="5";
    string b="";
    while(b.size()<a.size())
        b+="5";
    cout<<a<<endl<<b<<endl;
}