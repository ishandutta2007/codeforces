#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> mp;
string s[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ret=0;
    for (int i=0;i<n;i++){
        cin>>s[i];
        int mask=0;
        for (auto x:s[i]){
            mask^=(1<<(x-'a'));
        }
        for (int j=0;j<26;j++) {
            int nMask = mask^(1<<j);
            ret+=mp[nMask];
        }
        ret+=mp[mask];
        mp[mask]++;
    }
    cout<<ret<<endl;

}