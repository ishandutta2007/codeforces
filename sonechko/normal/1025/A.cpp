#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for (int j=0; j<s.size()-1; j++)
    if (s[j]==s[j+1]) {cout<<"Yes"; return 0;}
    if (n==1) cout<<"Yes"; else cout<<"No";
}