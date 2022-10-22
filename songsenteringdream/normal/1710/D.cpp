#include<cstdio>
const int o=2010;
int T,n,l[o],r[o];char s[o][o];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) l[i]=r[i]=i,scanf("%s",s[i]+i);
		for(int len=2;len<=n;++len) for(int i=1,j;i<=n-len+1;++i) if(s[i][j=i+len-1]>48&&l[i]-l[j]){
			printf("%d %d\n",i,j);
			int t[2]={i,j};
			for(int k=i+1,cur=1;k<l[j];++k) if(l[k]==k) printf("%d %d\n",t[cur],k),t[cur]=k,cur^=1;
			for(int L=l[i],R=r[j],k=L;k<=R;++k) l[k]=L,r[k]=R;
		}
	}
	return 0;
}