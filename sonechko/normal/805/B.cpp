#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9 + 7;
#define mod %MOD
const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s="";
    for (int i=1; i<=n; i++)
    if (i%4==1||i%4==2) cout<<"a"; else cout<<"b";
}