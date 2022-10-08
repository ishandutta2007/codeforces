#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pi;
const ll inf=(ll)1e18;
int next[100000];
int head[100000];
int e[100000];
int b[100000];
ll dd[100000];
int len[100000];
int cc[100000];
int tt[100000];
int kl,n,m,st,en;
ll d[2000][2000];
void add(int x,int y,int z){
	kl++;;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
	len[kl]=z;
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	scanf("%d%d",&st,&en);
	st--;
	en--;
	kl=0;
	int x,y,z;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		add(x,y,z);
		add(y,x,z);
	}
	for (int i=0;i<n;i++){
		scanf("%d%d",&tt[i],&cc[i]);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			d[i][j]=inf;
			b[j]=0;
		}
		d[i][i]=0;
		set<pi> q;
		for (int j=0;j<n;j++)
			q.insert(mp(d[i][j],j));
		//cerr<<"start "<<i<<endl;
		while (!q.empty()){
			int v=(*q.begin()).sc;
			q.erase(q.begin());
			//cerr<<v<<endl;
			b[v]=1;
			for (int bb=head[v];bb;bb=next[bb]) if (b[e[bb]]==0){
				if (d[i][e[bb]]>d[i][v]+len[bb]){
					q.erase(mp(d[i][e[bb]],e[bb]));
					d[i][e[bb]]=d[i][v]+len[bb];
					q.insert(mp(d[i][e[bb]],e[bb]));
				}
			}
		}
	}
/*	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cerr<<d[i][j]<<" ";
		}
		cerr<<endl;
	}*/
	for (int j=0;j<n;j++){
		dd[j]=inf;
		b[j]=0;
	}
	dd[st]=0;
	for (int j=0;j<n;j++){
		int mn=-1;
		for (int i=0;i<n;i++) if (b[i]==0 && ((mn==-1)||(dd[i]<dd[mn]))){
			mn=i;
		}
		b[mn]=1;
		for (int j=0;j<n;j++) if (b[j]==0 && d[mn][j]<=tt[mn]){
			dd[j]=min(dd[j],dd[mn]+cc[mn]);
		}
	}	
	/*for (int i=0;i<n;i++)
		cerr<<dd[i]<<endl;*/
	if (dd[en]==inf) cout<<"-1\n";
			    else cout<<dd[en]<<endl;
    return 0;
}