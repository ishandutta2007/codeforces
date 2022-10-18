#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 2e5 + 11;
map<int,int> mt;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int kol=0;
    int ans=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='1') kol++; else kol--;
        if (kol==0) ans=max(ans,i+1); else
        if (mt[kol]!=0) ans=max(ans,i-mt[kol]+1);
        if (mt[kol]==0) mt[kol]=i+1;
    }
    cout<<ans<<endl;
}