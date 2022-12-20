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

int dp[maxn];
string s[maxn];

pair<pii,int> solve(string &s,char ch){
    int a=0,b=0,c=0;
    while(a<sz(s) && s[a]==ch) a++;
    while(b<sz(s) && s[sz(s)-1-b]==ch) b++;
    int num=0;
    for(int i=0;i<sz(s);i++){
	if(s[i]==ch) c=max(c,++num);
	else         num=0;
    }
    return {{a,b},c};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    int ANS=0;
    for(char CH='a';CH<='z';CH++){
	auto P=solve(s[0],CH);
	dp[0]=P.S;
	for(int i=1;i<n;i++){
	    P=solve(s[i],CH);
	    if(P.S==sz(s[i]))
		dp[i]=(dp[i-1]+1)*(sz(s[i])+1)-1;
	    else
		dp[i]=max(P.S,dp[i-1]>0?1+P.F.F+P.F.S:0);
	}
	ANS=max(ANS,dp[n-1]);
    }
    return cout<<ANS<<endl,0;
}