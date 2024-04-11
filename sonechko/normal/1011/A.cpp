#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 100 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    kol[s[i]-'a']++;
    int t=-5,ans=0;
    for (int i=0; i<26; i++)
    {
        if (k==0) break;
        if (kol[i]==0) continue;
        if (i-t<2) continue;
        ans+=i+1;
        t=i;
        k--;
    }
    if (k>0) cout<<-1; else cout<<ans;
}