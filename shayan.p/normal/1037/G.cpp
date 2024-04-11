// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define all(s) s.begin(),s.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>fnd;
vector<int> Aft[maxn],Bef[maxn];
int pre[maxn][26],nxt[maxn][26];
bool is[26],in[27];

struct Fenwick{
    int arr[maxn];
    Fenwick(){
	memset(arr,0,sizeof arr);
    }
    void Add(int ind,int x){
	ind+=3;
	while(ind<maxn){
	    arr[ind]^=x;
	    ind+=ind & -ind;
	}
    }
    int Ask(int ind){
	ind+=3;
	int ans=0;
	while(ind>0){
	    ans^=arr[ind];
	    ind-=ind & -ind;
	}
	return ans;
    }
};Fenwick fen[26];

inline int Ask(int l,int r,int c){// be che chizaii niaz darim? kolle baze haye fenwick dakhelemoon ok bashan (baz r)  va aft o bef ham hamintor
    int ps=pre[r][c]; assert(ps>=0);
    int ans=fen[c].Ask(ps-1)^fen[c].Ask(l-1);
    if(ps<r) ans^=Aft[ps][r-ps-1];
    ps=nxt[l][c]; assert(ps<=r);
    if(l<ps) ans^=Bef[ps][ps-l-1];
    return ans;
}
void Unique(string &s){
    string str="";
    for(int i=0;i<sz(s);i++){
	if(str=="" || str.back()!=s[i])
	    str.PB(s[i]),fnd.PB(i);
    }
    s=str;
}
void Find(int &l,int &r){
    l=upper_bound(all(fnd),l)-fnd.begin()-1;
    r=upper_bound(all(fnd),r)-fnd.begin()-1;
}
int Mex(){
    for(int i=0;i<=26;i++)
	if(in[i]==0)
	    return i;
    assert(0);
}
bool CMP(pii a,pii b){
    if(a.S-a.F==b.S-b.F) return a<b;
    return a.S-a.F<b.S-b.F;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    Unique(s);
    for(int i=0;i<26;i++)
	pre[0][i]=-1,nxt[sz(s)-1][i]=sz(s);
    pre[0][s[0]-'a']=0;
    nxt[sz(s)-1][s.back()-'a']=sz(s)-1;
    for(int i=1;i<sz(s);i++)
	for(int j=0;j<26;j++)
	    pre[i][j]=(s[i]-'a'==j?i:pre[i-1][j]);
    for(int i=sz(s)-2;i>=0;i--)
	for(int j=0;j<26;j++)
	    nxt[i][j]=(s[i]-'a'==j?i:nxt[i+1][j]);
    vector<pii> tdo;
    for(int l=0;l<sz(s);l++){
	for(int r=l+1;r<sz(s) && s[l]!=s[r];r++){
	    tdo.PB({l+1,r});
	}
    }
    for(int r=0;r<sz(s);r++){
	for(int l=r-1;l>=0 && s[l]!=s[r];l--){
	    tdo.PB({l,r-1});
	}
    }
    sort(all(tdo),CMP);
    tdo.resize(unique(tdo.begin(),tdo.end())-tdo.begin());
    for(pii p:tdo){
	memset(is,0,sizeof is); memset(in,0,sizeof in);
	for(int i=0;i<26;i++){
	    int ps=pre[p.S][i];
	    if(ps<p.F) continue;
	    in[Ask(p.F,p.S,i)]=is[i]=1;
	}
	int num=Mex();
	bool bl1=(p.F!=0 && !is[s[p.F-1]-'a']),bl2=(p.S!=sz(s)-1 && !is[s[p.S+1]-'a']);
	if(bl1) Aft[p.F-1].PB(num);
	if(bl2) Bef[p.S+1].PB(num);
	if(bl1 && bl2 && s[p.F-1]==s[p.S+1]) fen[s[p.F-1]-'a'].Add(p.F-1,num);
    }
    int m;cin>>m;
    while(m--){
	int l,r;cin>>l>>r; --l,--r; Find(l,r);
      	memset(in,0,sizeof in);
	for(int i=0;i<26;i++){
	    int ps=pre[r][i];
	    if(ps<l) continue;
	    in[Ask(l,r,i)]=1;
	}
	if(in[0]) cout<<"Alice\n";
	else      cout<<"Bob\n";
    }
    return 0;
}