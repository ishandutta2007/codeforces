// Phoenix

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

const int maxn=4e6+10,mod=51123987;

int len[maxn];
int open[maxn],close[maxn];

int main(){
    int n;cin>>n;
    string S,s;cin>>S;
    for(int i=0;i<n;i++)
	s+='|',s+=S[i];
    s+='|';
    int pos=0;
    for(int i=0;i<sz(s);i++){
	if(len[pos]+pos>=i && 2*pos-i>=0)
	    len[i]=min(len[2*pos-i],len[pos]+pos-i);
	while(i-len[i]-1>=0 && i+len[i]+1<sz(s) && s[i-len[i]-1]==s[i+len[i]+1])
	    len[i]++;
	if(i+len[i]>pos+len[pos])
	    pos=i;
    }
    for(int i=0;i<sz(s);i++){
	open[i-len[i]]++;
	open[i+1]--;
	close[i]++;
	close[i+len[i]+1]--;
    }
    ll Op=0,Cl=0,smCl=0,smOp=0,ans=0;
    for(int i=0;i<sz(s);i++){
	Op+=open[i],Cl+=close[i];
	if(i&1) ans=(ans+Op*(smOp-smCl))%mod,ans+=(Op*(Op-1))/2,smOp=(smOp+Op)%mod,smCl=(smCl+Cl)%mod;
    }
    cout<<ans<<endl;
    return 0;
}