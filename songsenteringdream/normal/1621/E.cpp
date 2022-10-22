#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int o=1e6,E=1e5+3;
int T,n,m,a[o],k[o],mn[o],flg[o],col[o],asd;long long s[o];vector<int> b[o];
inline void pushdown(int id){
	if(col[id<<1]^asd) col[id<<1]=asd,mn[id<<1]=flg[id<<1]=0;
	if(col[(id<<1)|1]^asd) col[(id<<1)|1]=asd,mn[(id<<1)|1]=flg[(id<<1)|1]=0;
	mn[id<<1]+=flg[id];flg[id<<1]+=flg[id];
	mn[(id<<1)|1]+=flg[id];flg[(id<<1)|1]+=flg[id];
	flg[id]=0;
}
void modify(int id,int ql,int qr,int val,int l=1,int r=E){
	if(col[id]^asd) col[id]=asd,mn[id]=flg[id]=0;
	if(ql<=l&&r<=qr){mn[id]+=val;flg[id]+=val;return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d",&n,&m);++asd;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),modify(1,1,a[i],1);
		for(int i=1,j;i<=m;modify(1,1,(s[i]+k[i]-1)/k[i],-1),++i)
			for(scanf("%d",&k[i]),b[i].resize(k[i]),s[i]=j=0;j<k[i];)
				scanf("%d",&b[i][j]),s[i]+=b[i][j++];
		for(int i=1;i<=m;++i)
			for(int j=0;j<k[i];putchar(mn[1]<0?48:49),
			modify(1,1,(s[i]+k[i]-1)/k[i],-1),modify(1,1,(s[i]-b[i][j]+k[i]-2)/(k[i]-1),1),++j)
				modify(1,1,(s[i]+k[i]-1)/k[i],1),modify(1,1,(s[i]-b[i][j]+k[i]-2)/(k[i]-1),-1);
	}
	return 0;
}