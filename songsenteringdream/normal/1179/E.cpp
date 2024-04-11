#include<bits/stdc++.h>
using namespace std;
const int o=1010;const long long inf=1e18;
int n,a[o],b[o],c[o],tp;long long L,l[o],r[o];mt19937 rnd(time(0));
long long query(int id,long long x){cout<<"? "<<id<<" "<<x<<endl;cin>>x;return x;}
void slv(int il,int ir,long long vl,long long vr){
	if(il==ir){l[a[il]]=vl;r[a[ir]]=vr;return;}
	int im=il+ir>>1;long long ym,y=L/n*im,vm,yl,yr;
	for(int l=il,r=ir,i,p1,p2;1;){
		i=rnd()%(r-l+1)+l;p1=l;p2=r;tp=0;
		for(yl=vl,yr=vr;yl<yr;) if(query(a[i],ym=yl+yr>>1)<y) yl=ym+1;else yr=ym;
		for(int j=l;j<=r;++j) if((ym=query(a[j],yl))>y) b[p1++]=a[j];else if(ym<y) b[p2--]=a[j];else c[++tp]=a[j];
		for(int j=1;j<=tp;++j) b[p1+j-1]=c[j];
		for(int j=l;j<=r;++j) a[j]=b[j];
		if(p1<=im&&im<=p2){vm=yl;break;}
		if(p1<im) l=p1+1;
		else r=p1-1;
	}
	slv(il,im,vl,vm);slv(im+1,ir,vm,vr);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>L;
	for(int i=1;i<=n;++i) a[i]=i;
	slv(1,n,0,inf);
	cout<<"! ";
	for(int i=1;i<=n;++i) cout<<l[i]<<" "<<r[i]<<endl;
	return 0;
}