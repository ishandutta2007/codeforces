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
int n,k,root;
pi a[1000000];
int pr[1000000];
int mn[1000000];
int rg[1000000];
int zn[1000000];
ld ff[1000000];

ll pl1[1000000];
ll pl2[1000000];

vector<int> sn[1000000];
void dfs(int v){
	if (sn[v].size()==0) {
		mn[v]=zn[v];
		rg[v]=zn[v];
		return;
	}
	dfs(sn[v][0]);
	dfs(sn[v][1]);
	mn[v]=mn[sn[v][0]];
	rg[v]=rg[sn[v][1]];
}
void calc(int v,int l,int r){
	if (l==r) return;
	if (sn[v].size()==0) {
		return;
	}
	int md=upper_bound(a+l,a+r,mp(zn[v],0))-a;
	pl1[l]+=1;
	pl1[md]+=-1;
	pl2[l]+=mn[sn[v][1]];
	pl2[md]+=-mn[sn[v][1]];
	pl1[md]+=1;
	pl1[r]+=-1;
	pl2[md]+=rg[sn[v][0]];
	pl2[r]+=-rg[sn[v][0]];
	calc(sn[v][0],l,md);
	calc(sn[v][1],md,r);
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&pr[i],&zn[i]);
		pr[i]--;
		if (pr[i]==-2){
			root=i;
		} else {
			sn[pr[i]].pb(i);
		}
	}
	for (int i=0;i<n;i++)if (sn[i].size()==2){
		if (zn[sn[i][0]]>zn[sn[i][1]]){
			swap(sn[i][0],sn[i][1]);
		}
	}
	dfs(root);
	scanf("%d",&k);
	for (int i=0;i<k;i++){
		scanf("%d",&a[i].fs);
		a[i].sc=i;
	}
	sort(a,a+k);
	calc(root,0,k);
	ll tk1=0;
	ll tk2=0;
	for (int i=0;i<k;i++){
		tk1+=pl1[i];
		tk2+=pl2[i];
		ff[a[i].sc]=(tk2*((ld)1.0))/tk1;
	}
	for (int i=0;i<k;i++){
		printf("%.18lf\n",(double)ff[i]);
	}
    return 0;
}