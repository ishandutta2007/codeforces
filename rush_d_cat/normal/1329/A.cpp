#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,m,l[N],ans[N],det[N];
int main() {
	scanf("%d%d",&n,&m);
	int need=1e9;
	for(int i=1;i<=m;i++){
		scanf("%d",&l[i]);
		if(i+l[i]-1>n) return !printf("-1\n"); 
		ans[i]=i;
		need=min(need,n-(i+l[i]-1));
	}
	//printf("need=%d\n", need);
	for(int i=2;i<=m;i++){
		int sup=l[i-1]-1;
		det[i]=min(sup,need);
		need-=det[i];
	}
	if(need>0)return !printf("-1\n");
	for(int i=1;i<=m;i++){
		det[i]+=det[i-1]; ans[i]+=det[i]; 
		printf("%d ", ans[i]);
	}
}