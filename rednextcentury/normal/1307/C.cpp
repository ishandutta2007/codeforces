#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[100];
ll inv[100][100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    ll ret=0;
    for (auto x:s){
        for (int i=0;i<26;i++) {
            inv[i][x-'a']+=cnt[i];
            ret=max(ret,inv[i][x-'a']);
        }
        cnt[x-'a']++;
        ret=max(ret,cnt[x-'a']);
    }
    cout<<ret<<endl;
}