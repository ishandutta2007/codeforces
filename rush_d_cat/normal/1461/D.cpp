#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200000 + 10;
int t;
int n,q,a[N]; LL s[N];
int pos(int x){
	return upper_bound(a+1,a+1+n,x) - a - 1;
}
set<LL> ans;
void build(int l,int r){
	ans.insert(s[r] - s[l-1]);

	if(l==r) return;
	int val=(a[l]+a[r])/2;
	int mid=pos(val);
	/*
	printf("build %d %d\n", l,r);
	printf("val=%d,mid=%d\n", val,mid);
	for(int i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
	*/
	if(mid==r) return;
	build(l,mid); build(mid+1,r);
}
int main() {
	scanf("%d", &t);
	while(t--){
    	scanf("%d%d",&n,&q);
    	for(int i=1;i<=n;i++){
    		scanf("%d",&a[i]); 
    	}
    	sort(a+1,a+1+n);
    	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    	ans.clear();
    	build(1,n);
    	for(int i=1;i<=q;i++){
    		int x; scanf("%d",&x);
    		printf("%s\n",ans.find(x)!=ans.end()?"Yes":"No");
    	}
    }
}