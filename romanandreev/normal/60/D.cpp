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
const int KV=1000010;
const int KE=12000010;
int next[KE];
int head[KV];
int w[KV];
int a[KV];
int e[KE];
int kl=0;
int n;
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
void add(int x,int y){
	kl++;
	next[kl]=head[x];
	head[x]=kl;
	e[kl]=y;
}
void dfs(int v){
	w[v]=1;
	for (int bb=head[v];bb;bb=next[bb]){
		if (w[e[bb]]==0)
			dfs(e[bb]);
	}
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int K=5000;
	int x,y,z,f1,f2,f3;
	for (int N=1;N<=K;N++)
		for (int M=N;M<=K;M++) if ((gcd(N,M)==1) && (((N%2)==0) || ((M%2)==0))){
			x=M*M-N*N;
			y=2*M*N;
			z=M*M+N*N;
			f1=lower_bound(a,a+n,x)-a;
			if (f1==n || a[f1]!=x) f1=n;
			f2=lower_bound(a,a+n,y)-a;
			if (f2==n || a[f2]!=y) f2=n;
			f3=lower_bound(a,a+n,z)-a;
			if (f3==n || a[f3]!=z) f3=n;
			if (f1!=n && f2!=n){
				add(f1,f2);
				add(f2,f1);
			}	
			if (f1!=n && f3!=n){
				add(f1,f3);
				add(f3,f1);
			}	
			if (f3!=n && f2!=n){
				add(f3,f2);
				add(f2,f3);
			}				
		}
	int ans=0;
	for (int i=0;i<n;i++) if (w[i]==0){
		ans++;
		dfs(i);
	}
	printf("%d\n",ans);
    return 0;
}