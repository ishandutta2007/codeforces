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

const int maxn=1e5+10,mod=1e9+7,P1=911382323,P2=972663749,inf=2e9;

int k[maxn],ln[maxn];
vector<int>v[maxn];
int nxt[maxn][26],C=2,wh[maxn],f[maxn],up[maxn];

void Add(string &s,int id){
    int tmp=1;
    for(int i=0;i<sz(s);i++){
	if(nxt[tmp][s[i]-'a']==0)
	    nxt[tmp][s[i]-'a']=C++;
	tmp=nxt[tmp][s[i]-'a'];
    }
    wh[tmp]=id;
}

void bfs(){
    queue<int>q;
    q.push(1);
    for(int i=0;i<26;i++)
	nxt[1][i]+=nxt[1][i]==0;
    while(!q.empty()){
	int u=q.front();
	q.pop();
	up[u]=wh[f[u]]==0?up[f[u]]:f[u];
	for(int i=0;i<26;i++){
	    if(nxt[u][i]>1){
		int y=nxt[u][i];
		f[y]=f[u];
		while(f[y]>0 && nxt[f[y]][i]==0)
		    f[y]=f[f[y]];
		f[y]=u==1?1:nxt[f[y]][i];
		q.push(y);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    string s;cin>>s;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	string s;cin>>k[i]>>s;
	Add(s,i);
	ln[i]=sz(s);
    }
    bfs();
    int nw=1;
    for(int i=0;i<sz(s);i++){
	int id=s[i]-'a';
	if(nxt[nw][id]==0){
	    while(nxt[nw][id]==0)
		nw=f[nw];
	    nw=nxt[nw][id];
	}
	else{
	    nw=nxt[nw][id];
	}
	int NW=nw;
	while(NW>0){
	    if(wh[NW]!=0)
		v[wh[NW]].PB(i);
	    NW=up[NW];
	}
    }
    for(int i=1;i<=n;i++){
	int ans=inf;
	for(int j=k[i]-1;j<sz(v[i]);j++)
	    ans=min(ans,v[i][j]-v[i][j-k[i]+1]+ln[i]);
	cout<<(ans==inf?-1:ans)<<"\n";
    }
    return 0;
}