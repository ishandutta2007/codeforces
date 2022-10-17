#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;vector<int>E[N];
int n,m,Q,L,R,A[N],P[N],T[N],B[N];
void get(int x,int y) {
	int lx=E[x].size()-1,ly=E[y].size()-1;
	for(; lx>=0; lx--) {
		while(ly>=0&&E[y][ly]>E[x][lx])ly--;
		if(ly==(int)E[y].size()-1)T[E[x][lx]]=0;
		else T[E[x][lx]]=E[y][ly+1];
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; i++)scanf("%d",&P[i]);
	for(int i=1; i<=m; i++)scanf("%d",&A[i]);
	for(int i=1; i<=m; i++)
		E[A[i]].push_back(i);
	for(int i=1; i<=n; i++) {
		if(i==n)get(P[i],P[1]);
		else get(P[i],P[i+1]);
	}
	for(int i=1; i<=m; i++)B[i]=i;
	for(int i=0; (1<<i)<n; i++) {
		if((n-1)&(1<<i))
			for(int j=1; j<=m; j++)
				B[j]=T[B[j]];
		for(int j=1; j<=m; j++)T[j]=T[T[j]];
	}
	for(int i=1; i<=m; i++)
		if(B[i]==0)B[i]=1e9;
	for(int i=m-1; i>0; i--)
		B[i]=min(B[i],B[i+1]);
	for(int i=1; i<=Q; i++) {
		scanf("%d%d",&L,&R);
		if(B[L]<=R)printf("1");
		else printf("0");
	}
	return 0;
}