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


const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol=0;
    string s;
    cin>>s;
    for (int i=1; i<s.size(); i++)
        if (s[i]=='S'&&s[i-1]=='F') kol++; else
        if (s[i]=='F'&&s[i-1]=='S') kol--;
    if (kol<0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}