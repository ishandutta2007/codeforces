#include<bits/stdc++.h>
const int N=303,M=1e9;
using namespace std;
int n,m,t,tx,ta,f[N][N],ans;
struct seg{
	int l,r,no;
}s[N];
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d",&tx,&ta),
	s[m++]={tx-ta,tx,i},
	s[m++]={tx,tx+ta,i};
	s[m++]={-M,-M,n};
	sort(s,s+m,[](seg a,seg b){
		return a.l<b.l;
	});/*
	for(int i=0;i<m;i++)
	cerr<<i<<":{"<<s[i].l<<','<<s[i].r<<"}\n";*/
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++){
		ans=max(ans,f[i][j]);
		//cerr<<"("<<i<<','<<j<<")"<<f[i][j]<<endl;
		for(int k=0;k<m;k++)
		if(s[k].l>s[j].r&&s[k].l>s[i].l&&s[k].no^s[i].no)
		f[k][i]=max(f[k][i],f[i][j]+s[k].r-max(s[k].l,s[i].r));
	}
	printf("%d",ans);
}