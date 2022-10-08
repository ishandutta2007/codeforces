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
typedef pair<int,int> pi;
const int inf=(int)1e9;
int next[1000000];
int head[1000000];
int e[1000000];
int b[1000000];
int g[1000000];
int r[1000000];

int n,m,c,kl;
void add(int x,int y){
	kl++;;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
}
void dfs(int v){
	b[v]=1;
	c++;
	for (int bb=head[v];bb;bb=next[bb]){
		if (b[e[bb]]==0)
			dfs(e[bb]);
	}
}
bool lucky(int k){
	while (k>0){
		if (k%10!=4 && k%10!=7)
			return false;
		k/=10;
	}
	return true;
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	kl=0;
	int x,y;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		add(x,y);
		add(y,x);
	}
	for (int i=0;i<n;i++){
		if (b[i]==0){
			c=0;
			dfs(i);
			g[c]++;
		}
	}

	/*memset(g,0,sizeof(g));
	n=100000;
	for (int i=1;i<=n;i++){
		g[1]++;
	}*/


	vector<int> vv;
	vector<pi> v;
	for (int i=1;i<=n;i++) if (g[i]>0){		
		for (int j=0;j<=20;j++) if (((g[i]>>j)&1)==1){
			for (int k=0;k<j;k++){
				v.pb(mp(i*(1<<k),1<<k));
			}
			v.pb(mp(i,1));
		}
	}
	sort(v.begin(),v.end());
	for (int i=1;i<=n;i++){
		if (lucky(i))
			vv.pb(i);
	}
	for (int i=0;i<=n;i++){
		r[i]=inf;
	}
	r[0]=0;
	int mm=(int)v.size();
	for (int j=0;j<mm;j++)
		for (int i=n-v[j].fs;i>=0;i--)
			if (r[i]!=inf){
				if (r[i+v[j].fs]>r[i]+v[j].sc){
					r[i+v[j].fs]=r[i]+v[j].sc;
				}
	}
	int ans=inf;
	for (int i=0;i<(int)vv.size();i++){
		ans=min(ans,r[vv[i]]);
	}
	if (ans==inf)
		cout<<"-1"<<endl;
	else
		cout<<ans-1<<endl;
    return 0;
}