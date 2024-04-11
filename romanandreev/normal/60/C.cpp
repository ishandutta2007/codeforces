#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
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
int head[1000000];
int next[1000000];
int e[1000000];
int w[1000000];
ll nok[1000000];
ll nod[1000000];
int ans[1000000];
int f1[1000000];
int f2[1000000];
int cnt;
int kl=0;
ll gcd(ll x,ll y){
	if (y==0) return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return (x*y/gcd(x,y));
}
void add(int x,int y,int z,int w){
	kl++;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
	nod[kl]=z;
	nok[kl]=w;
}
bool dfs(int v,ll c){
	w[v]=cnt;
	ans[v]=c;
	for (int bb=head[v];bb;bb=next[bb]){
		ll t=nod[bb]*nok[bb]/c;
		if (t>1000000) return false;
		if (gcd(c,t)!=nod[bb]) return false;
		if (lcm(c,t)!=nok[bb]) return false;
		if (w[e[bb]]==cnt){
			if (ans[e[bb]]!=t) return false;
		} else {
			if (!dfs(e[bb],t)) return false;
		}		
	}	
	return true;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,x,y,z,W;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		f1[i]=1;
		f2[i]=1;	
	}
	for (int i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&z,&W);
		f1[x]=z;
		f2[x]=W;
		f1[y]=z;
		f2[y]=W;
		add(x,y,z,W);
   		add(y,x,z,W);
	}	
	for (int i=1;i<=n;i++) if (w[i]==0){
		bool bol=false;
		for (int j=f1[i];j<=f2[i];j++){
			cnt++;
			if (dfs(i,j)){
				bol=true;
				 break;
			}
		}
		if (!bol) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
    return 0;
}