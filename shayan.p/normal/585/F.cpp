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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

vector<vector<int> > trie,dp;
vector<int>vec,vec2;
bool ok[maxn];
int tn[100],f[maxn],ANS;
string s,A,B;
vector<int>vv;

int solve(int d){
    int tmp=0;
    for(int i=0;i<sz(vv);i++){
	tmp=trie[tmp][vv[i]];
	if(ok[tmp]) return tn[d-sz(vv)];
    }
    return dp[tmp][d-sz(vv)];
}

void PF(string &s){
    for(int i=1;i<sz(s);i++)
	s[i-1]=s[i];
    s.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    tn[0]=1;
    for(int i=1;i<100;i++)
	tn[i]=1ll*10*tn[i-1] %mod;
    cin>>s>>A>>B;
    int D=sz(A),d=sz(A)/2;
    vec.resize(10);   vec2.resize(D+1);   trie.PB(vec); dp.PB(vec2);
    for(int i=0;i<sz(s)-d+1;i++){
	int tmp=0;
	for(int j=i;j<i+d;j++){
	    if(trie[tmp][s[j]-'0']==0)
		trie[tmp][s[j]-'0']=sz(trie),trie.PB(vec),dp.PB(vec2);
	    tmp=trie[tmp][s[j]-'0'];
	}
	ok[tmp]=1;
    }
    queue<int>q;
    for(int i=0;i<10;i++){
	if(trie[0][i]!=0)
	    q.push(trie[0][i]);
    }
    while(sz(q)){
	int u=q.front(); q.pop();
	for(int i=0;i<10;i++){
	    if(trie[u][i]==0)
		trie[u][i]=trie[f[u]][i];
	    else
		f[trie[u][i]]=trie[f[u]][i],q.push(trie[u][i]);
	}
    }
    for(int i=0;i<sz(trie);i++){
	dp[i][0]=ok[i];
    }
    for(int i=0;i<sz(trie);i++){
	if(ok[i]) dp[i][1]=10;
	else for(int j=0;j<10;j++) dp[i][1]+=ok[trie[i][j]];
    }
    for(int i=2;i<=D;i++){
	for(int j=0;j<sz(dp);j++){
	    dp[j][i]=1ll*10*dp[j][i-1] %mod;
	    for(int k=0;k<10;k++){
		if(!ok[trie[j][k]])
		    dp[j][i]=(1ll*dp[j][i]+dp[trie[j][k]][i-1]-1ll*10*dp[trie[j][k]][i-2])%mod;
	    }
	}
    }    
    while(sz(A) && A[0]==B[0]){
	vv.PB(A[0]-'0');
	PF(A);PF(B);
    }
    if(A.empty()){
	ANS=solve(D);
    }
    else{
	for(int x=A[0]-'0'+1;x<B[0]-'0';x++){
	    vv.PB(x);
	    ANS=(ANS+solve(D))%mod;
	    vv.pop_back();
	}
	vv.PB(A[0]-'0');
	for(int i=1;i<sz(A);i++){
	    for(int x=A[i]-'0'+1;x<10;x++){
		vv.PB(x);
		ANS=(ANS+solve(D))%mod;
		vv.pop_back();
	    }
	    vv.PB(A[i]-'0');
	}
	ANS=(ANS+solve(D))%mod;

	for(int i=0;i<sz(A);i++){
	    vv.pop_back();
	}
	
	vv.PB(B[0]-'0');
	for(int i=1;i<sz(B);i++){
	    for(int x=0;x<B[i]-'0';x++){
		vv.PB(x);
		ANS=(ANS+solve(D))%mod;
		vv.pop_back();
	    }
	    vv.PB(B[i]-'0');
	}
	ANS=(ANS+solve(D))%mod;
    }
    if(ANS<0) ANS+=mod;
    return cout<<ANS<<endl,0;
}