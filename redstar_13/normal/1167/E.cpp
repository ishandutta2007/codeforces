#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long INT;
typedef vector<int> VI;
#define NN 1000010
int a[NN];
VI v[NN];
int f[NN],g[NN];
int p,q;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].pb(i);
	}
	INT ans=1;
	for(int i=1;i<=x;i++) sort(v[i].begin(),v[i].end());
	int st=0;
	for(int i=1;i<=x;i++){
		int sz=v[i].size()-1;
		if(sz<0){
			f[++p]=st;
			continue;
		}
		if(v[i][0]<st) break;
		st=v[i][sz];
		f[++p]=st;
	}
	if(p==x){
		printf("%I64d\n",(INT)x*(x+1)/2);
		return 0;
	}
	st=n+1;
	for(int i=x;i>=1;i--){
		int sz=v[i].size()-1;
		if(sz<0){
			g[++q]=st;
			continue;
		}
		if(v[i][sz]>st) break;
		st=v[i][0];
		g[++q]=st;
	}
	reverse(g+1,g+q+1);
	ans+=p+q;
	for(int i=1;i<=p;i++){
		int id=upper_bound(g+1,g+q+1,f[i])-g;
		ans+=q-id+1;
	}
	printf("%I64d\n",ans);
    return 0;
}