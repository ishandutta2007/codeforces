#include <bits/stdc++.h>
#define ll long long
using namespace std;
string get(string s)
{
    if (s.size()%2)return s;
    string l = get(s.substr(0,s.size()/2));
    string r = get(s.substr(s.size()/2,s.size()/2));
    if (r>l)swap(l,r);
    return l+r;
}
bool equiv(string a,string b)
{
    return get(a)==get(b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    if (equiv(a,b))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}