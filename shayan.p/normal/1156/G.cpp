// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define hash sth_strange

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3010,mod=1e9+9,P=1e6+3;
const ll inf=1e18;

map<string,int>mp;
string who[maxn];
int C,L[maxn],R[maxn];

vector<int>v[maxn];

int what[maxn];

bool mark[maxn];

void dfs(int u){
    if(mark[u]==1) return;
    mark[u]=1;
    if(L[u]==-1){
	int &hsh=what[u];
	for(int i=0;i<sz(who[u]);i++)
	    hsh=(1ll*hsh*P+who[u][i])%mod;
    }
    else{
	dfs(L[u]);
	dfs(R[u]);
	int &hsh=what[u];
	hsh=what[L[u]];
	for(int i=0;i<sz(who[u]);i++)
	    hsh=(1ll*hsh*P %mod *117+who[u][i])%mod;
	hsh=(1ll*hsh*P %mod *101 * 17+what[R[u]])%mod;
    }
}


vector<string>ans;
map<int,string>name;

int Cn=0;
char CC='a';

inline string New(){
    string s; s.PB(CC);
    if(Cn==1000) CC++,Cn=0;
    int x=Cn++;
    for(int i=0;i<3;i++)
	s+='0'+(x%10),x/=10;
    if(mp.count(s)) return New();
    return s;
}

void dfs2(int u){
    if(name.count(what[u])) return;
    if(L[u]==-1){
	name[what[u]]=who[u];
    }
    else{
	dfs2(L[u]);
	dfs2(R[u]);
	string nm=New();
	if(u==mp["res"]) nm="res";
	ans.PB( nm+"="+name[what[L[u]]]+who[u]+name[what[R[u]]] );
	name[what[u]]=nm;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	string s;cin>>s;
	string s1,s2,s3; string op;
	int pt=0;
	while(s[pt]!='=') s1+=s[pt++];
	pt++;
	while(pt<sz(s) && s[pt]!='&' && s[pt]!='#' && s[pt]!='^' && s[pt]!='$') s2+=s[pt++];
	if(pt==sz(s)){
	    if(!mp.count(s2)) who[C]=s2, L[C]=-1, mp[s2]=C++;
	    mp[s1]=mp[s2];
	}
	else{
	    op.PB(s[pt++]);
	    while(pt<sz(s)) s3+=s[pt++];
	    if(!mp.count(s2)) who[C]=s2, L[C]=-1, mp[s2]=C++;
	    if(!mp.count(s3)) who[C]=s3, L[C]=-1, mp[s3]=C++;
	    who[C]=op, L[C]=mp[s2], R[C]=mp[s3] ,mp[s1]=C++;
	}			
    }
    if(!mp.count("res")){
	return cout<<0<<endl,0;
    }
    dfs(mp["res"]);
    dfs2(mp["res"]);

    if(sz(ans)==0){
	if(who[mp["res"]]=="res") return cout<<0<<endl,0;
	else return cout<<"1\n"<<"res="<<who[mp["res"]]<<endl,0;
    }
    else{
	cout<<sz(ans)<<"\n";
	for(string &str:ans){
	    cout<<str<<"\n";
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.