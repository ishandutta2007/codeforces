#include<stdio.h>
char S[8][9];
long N[8];
bool in[8];
const long mi[10]={1,10,100,1000,10000,100000,1000000,10000000};
long maxx,minx,ans=~0U>>1;
long n,m;
inline void upmin(long &x,const long y){
	if(y<x) x=y;
}
inline void upmax(long &x,const long y){
	if(x<y) x=y;
}
inline void calc(){
	maxx=0,minx=~0U>>1;
	for(register long ii=0;ii<n;++ii)
		upmax(maxx,N[ii]),upmin(minx,N[ii]);
	upmin(ans,maxx-minx);
}

void dfs(const long wh){
	if(wh==m){calc();return;}
	for(long ii=0;ii<m;++ii)
		if(!in[ii]){
			in[ii]=1;
			for(long jj=0;jj<n;++jj) N[jj]+=(S[jj][wh]-'0')*mi[ii];
			dfs(wh+1);
			for(long jj=0;jj<n;++jj) N[jj]-=(S[jj][wh]-'0')*mi[ii];
			in[ii]=0;
			}
}
int main(){
	scanf("%ld%ld",&n,&m);
	for(long i=0;i<n;++i) scanf("%s",S[i]);
	dfs(0);
	printf("%ld\n",ans);
	scanf("%ld%ld",&n,&m);
	return 0;
}