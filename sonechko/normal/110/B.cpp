#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        if (i%4==1) cout<<"a"; else
        if (i%4==2) cout<<"b"; else
        if (i%4==3) cout<<"c"; else cout<<"d";

}