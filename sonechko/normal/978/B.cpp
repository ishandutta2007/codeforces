#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int j=0; j<s.size(); j++)
        if (j>=2&&s[j-1]=='x'&&s[j-2]=='x'&&s[j]=='x') ans++;
    cout<<ans<<endl;
}