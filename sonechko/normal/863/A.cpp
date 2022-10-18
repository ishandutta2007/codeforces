#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int kol=0;
    for (int i=s.size()-1; i>=0; i--)
        if (s[i]=='0') kol++; else break;
    int kol2=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='0') kol2++; else break;
    while (kol>kol2)
    {
        s="0"+s;
        kol2++;
    }
    for (int i=0; i<s.size(); i++)
    if (s[i]!=s[s.size()-i-1]) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}