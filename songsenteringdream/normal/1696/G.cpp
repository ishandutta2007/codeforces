#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;const double eps=1e-9,inf=1e18;
struct Matrix{
	double a[3][3];
	Matrix operator*(Matrix B){
		Matrix C;
		for(int i=0;i<3;++i) for(int j=0;j<3;++j)
			for(int k=C.a[i][j]=0;k<3;++k) C.a[i][j]=max(C.a[i][j],a[i][k]+B.a[k][j]);
		return C;
	}
}v[o*4],t;
int n,q,X,Y;double z[3];
void modify(int id,int pos,Matrix val,int l=1,int r=n){
	if(l==r){v[id]=val;return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	v[id]=v[id<<1]*v[(id<<1)|1];
}
Matrix query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return v[id];
	int md=l+r>>1;
	if(qr<=md) return query(id<<1,ql,qr,l,md);
	if(md<ql) return query((id<<1)|1,ql,qr,md+1,r);
	return query(id<<1,ql,qr,l,md)*query((id<<1)|1,ql,qr,md+1,r);
}
Matrix calc(int a){
	Matrix res;
	for(int i=0;i<3;++i) for(int j=0;j<3;++j)
		if(X*z[i]+Y*z[j]<=1+eps&&Y*z[i]+X*z[j]<=1+eps) res.a[i][j]=z[j]*a;
		else res.a[i][j]=-inf;
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&q,&X,&Y);
	if(X>Y) swap(X,Y);
	z[1]=1.0/(X+Y);z[2]=1.0/Y;
	for(int i=1,a;i<=n;++i) scanf("%d",&a),modify(1,i,calc(a));
	for(int opt,x,y;q--;){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) modify(1,x,calc(y));
		else t=query(1,x,y),printf("%.9lf\n",max(t.a[0][0],max(t.a[0][1],t.a[0][2])));
	}
	return 0;
}