#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;
const int MOD = 998244353;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int kol0=0,pos=s.size()+1;
    for (int j=0; j<s.size(); j++)
    if (s[j]=='0') kol0++; else 
    if (s[j]=='2') {pos=j; break;}
    for (int j=0; j<kol0; j++)
    cout<<'0';
    for (int j=0; j<s.size(); j++)
    if (s[j]=='1') cout<<'1';
    for (int j=pos; j<s.size(); j++)
    if (s[j]!='1') cout<<s[j];
}