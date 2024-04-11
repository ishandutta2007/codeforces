#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define y1 dhnfg
#define ld long double

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k1=0,k2=0;
    for (int i=0; i<s.size(); i++)
    if (s[i]=='o') k1++; else k2++;
    if (k1==0||k2%k1==0) {cout<<"YES"<<endl; return 0;}
    cout<<"NO"<<endl;
}