#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    for (int j=0; j<s.size(); j++)
    if (s[j]=='a'&&b==0&&c==0) a++; else
    if (s[j]=='b'&&c==0) b++; else
    if (s[j]=='c') c++; else {cout<<"NO"<<endl; return 0;}
    if (a!=0&&b!=0&&(a==c||b==c)) cout<<"YES"<<endl;
    else cout<<"NO";
}