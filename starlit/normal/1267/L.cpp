#include<bits/stdc++.h>
const int N=1003;
using namespace std;
int n,l,k,fr,as,at,no[N];
char S[N*N],a[N][N];
bool cmp(int x,int y){
	for(int i=0;i<l;i++)
	if(a[x][i]^a[y][i])
	return a[x][i]<a[y][i];
	return 0;
}
int main(){
	scanf("%d%d%d%s",&n,&l,&k,S);
	sort(S,S+n*l);
	at=n*l;
	for(int i=0;i<l;i++){
		for(int j=fr;j<k;j++)
		//cerr<<j<<':'<<S[as]<<endl,
		a[j][i]=S[as++];
		for(;fr<k-1&&a[fr][i]<a[k-1][i];fr++){
			for(int j=i+1;j<l;j++)
			a[fr][j]=S[--at];
		}
		//cerr<<fr<<"??\n";
	}
	for(int i=k;i<n;i++)
	for(int j=0;j<l;j++)
	a[i][j]=S[--at];
	for(int i=0;i<n;i++)
	no[i]=i;
	sort(no,no+n,cmp);
	for(int i=0;i<n;i++)
	puts(a[no[i]]);
}