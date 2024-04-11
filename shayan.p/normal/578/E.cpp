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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii> v[2][2];
vector<int>posl,posr;
int f[maxn],g[maxn];
bool mark[maxn];

inline void add(int a,int b){
    f[a]=b;
    g[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(f,-1,sizeof f);
    memset(g,-1,sizeof g);
    string s;cin>>s;
    for(int i=0;i<sz(s);i++){
	if(s[i]=='L')
	    posl.PB(i);
	else
	    posr.PB(i);
    }
    int pt1=0,pt2=0;
    while(pt1<sz(posl) && pt2<sz(posr)){
	while(pt2<sz(posr) && posl[pt1]>posr[pt2])
	    pt2++;
	if(pt2<sz(posr))
	    add(posl[pt1++],posr[pt2++]);
    }
    pt1=pt2=0;
    while(pt1<sz(posr) && pt2<sz(posl)){
	while(pt2<sz(posl) && posr[pt1]>posl[pt2])
	    pt2++;
	if(pt2<sz(posl))
	    add(posr[pt1++],posl[pt2++]);
    }
    for(int i=0;i<sz(s);i++){
	if(!mark[i]){
	    int tmp=i,A=s[i]=='R',B,ps=i;
	    while(tmp!=-1)
		mark[tmp]=1,B=s[tmp]=='R',ps=tmp,tmp=f[tmp];
	    v[A][B].PB({i,ps});
	}
    }
    int tot=sz(v[0][0])+sz(v[0][1])+sz(v[1][0])+sz(v[1][1]),ans=tot-1;
    while(tot>1){
	for(int i=0;i<2;i++){
	    for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){
		    if(i!=j && j==k) continue;
		    if(sz(v[i][j]) && sz(v[1-j][k])){
			pii A=v[i][j].back(),B=v[1-j][k].back();
			v[i][j].pop_back();v[1-j][k].pop_back();
			add(A.S,B.F);
			v[i][k].PB({A.F,B.S});
			--tot;
		    }
		}
	    }
	}
	for(int i=0;i<2;i++){
	    if(sz(v[i][1-i]) && sz(v[1-i][i])){
		pii A=v[i][1-i].back(),B=v[1-i][i].back();
		v[i][1-i].pop_back();v[1-i][i].pop_back();
		if(A.S<B.S){
		    int x=g[B.S];
		    g[B.S]=f[x]=-1;
		    add(A.S,B.S);add(B.S,B.F);
		    v[i][1-i].PB({A.F,x});
		    --tot;
		}
		else{
		    int x=g[A.S];
		    g[A.S]=f[x]=-1;
		    add(B.S,A.S);add(A.S,A.F);
		    v[1-i][i].PB({B.F,x});
		    --tot;
		}
	    }
	    if(sz(v[i][1-i])>1){
		pii A=v[i][1-i].back();
		v[i][1-i].pop_back();
		pii B=v[i][1-i].back();
		v[i][1-i].pop_back();
		add(A.S,B.F);
		v[i][1-i].PB({A.F,B.S});
		--tot;
	    }
	}
    }
    cout<<ans<<endl;
    int start=0;
    for(int i=0;i<sz(s);i++)
	if(g[i]==-1)
	    start=i;
    for(int i=0;i<sz(s);i++)
	cout<<start+1<<" ",start=f[start];
    return cout<<endl,0;
}