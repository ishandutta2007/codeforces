// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int cnt[30];

bool pal(string &s){
    for(int i=0;i<sz(s);i++){
	if(s[i]!=s[sz(s)-1-i])
	    return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    for(char ch:s){
	cnt[ch-'a']++;
    }
    for(int i=0;i<26;i++){
	if(cnt[i]&1) cnt[i]--;
    }
    int CNT=0;
    for(int i=0;i<26;i++){
	CNT+=cnt[i]>0;
    }
    if(CNT<=1){
	return cout<<"Impossible\n",0;
    }
    for(int i=0;i<sz(s)-1;i++){
	string ss=s.substr(i+1)+s.substr(0,i+1);
	if(pal(ss) && s!=ss) return cout<<1<<endl,0;
    }
    return cout<<2<<endl,0;
}