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

int pos[26];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s,ans;cin>>s;
    while(true){
	memset(pos,-1,sizeof pos);
	int a=-1,b=-1;
	for(int i=0;i<sz(s);i++){
	    if(pos[s[i]-'A']==-1)
		pos[s[i]-'A']=i;
	    else
		a=pos[s[i]-'A'],b=i;
	}
	if(a+1==b) return cout<<"Impossible\n",0;
	if(b>=13 && a-25+b>=0 && a-25+b<=1){
	    ans="";
	    for(int i=0;i<sz(s);i++){
		if(i==b) continue;
		ans+=s[i];
	    }
	    break;
	}
	s=s.back()+s;
	s.pop_back();
    }
    string ans1=ans.substr(0,13),ans2=ans.substr(13);
    reverse(ans2.begin(),ans2.end());
    return cout<<ans1<<"\n"<<ans2<<endl,0;
}