#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    if (s*v1+t1*2<s*v2+t2*2) cout<<"First"; else
    if (s*v1+t1*2>s*v2+t2*2) cout<<"Second"; else
    cout<<"Friendship";
}