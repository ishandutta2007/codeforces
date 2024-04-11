#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool taken[1000000];
int par[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int r=0;
        int n=s.size();
        string ret="";
        for (int i=0;i<n;i++)taken[i]=0,par[i]=(s[i]-'0')%2;
        for (int i=0;i<n;i++) {
            if (taken[i])continue;
            while(r<n && (par[r]==par[i] || taken[r]))r++;
            if (r<n && s[r]<s[i])ret+=s[r],taken[r]=1,r++,i--;
            else ret+=s[i],taken[i]=1;
        }
        cout<<ret<<'\n';
    }
}