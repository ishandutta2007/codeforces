#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,int> mp;
string x;
string brute;
ll ret=0;
map<string,int> vis;
void Try(int i){
    if (i==x.size()){
        string bla="";
        for (auto c:brute)if (c!='?')bla+=c;
        if (!vis[bla])
        if (mp.count(bla))ret+=mp[bla];
        vis[bla]=1;
    } else {
        if (brute[i]=='?'){
            Try(i+1);
            for (char c='a';c<='e';c++){
                brute[i]=c;
                Try(i+1);
            }
            brute[i]='?';
        } else Try(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        mp[s]++;
    }
    while(m--){
        cin>>x;
        vis.clear();
        brute=x;
        ret=0;
        Try(0);
        cout<<ret<<endl;
    }
}