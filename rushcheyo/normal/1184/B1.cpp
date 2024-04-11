#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct Node{
	int d,g;
}a[N];int b[N],s[N];
inline bool cmp(Node a,Node b){
	return a.d<b.d;
}
int main (){
	int n,m;scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%d",&s[i]);
	for (int i=1;i<=m;i++) scanf ("%d%d",&a[i].d,&a[i].g);
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++) a[i].g+=a[i-1].g,b[i]=a[i].d;
	for (int i=1;i<=n;i++){
		int p=upper_bound(b+1,b+m+1,s[i])-b-1;
		printf ("%d ",a[p].g);
	}
	return 0;
}