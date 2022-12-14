#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int ret=0;
    for (int i=0;i<x;i++) {
        if (s[i]=='1' && i!=y)ret++;
    }
    if (s[y]=='0')ret++;
    cout<<ret<<endl;
}