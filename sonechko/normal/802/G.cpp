#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k=1;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='h'&&k==1) k=2; else
        if (s[i]=='e'&&k==2) k=3; else
        if (s[i]=='i'&&k==3) k=4; else
        if (s[i]=='d'&&k==4) k=5; else
        if (s[i]=='i'&&k==5) k=6;
    if (k==6) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}