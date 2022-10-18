#include <cstdio>
const int Maxm=100000;
int l,r;
int n=32;
struct Edge{
	int u,v,w;
}edge[Maxm+5];
int mp[50][50];
int m;
void add_edge(int u,int v,int w){
	m++;
	mp[u][v]=w;
	edge[m].u=u;
	edge[m].v=v;
	edge[m].w=w;
}
int p[50],p_len;
int main(){
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&l,&r);
	puts("YES");
	if(l==r){
		puts("2 1");
		printf("1 2 %d\n",l);
		return 0;
	}
	r-=l;
	add_edge(1,n,l);
	add_edge(n-1,n,l);
	add_edge(1,n-1,1);
	for(int i=2;i<n-1;i++){
		if((1<<(i-2))+1>r){
			break;
		}
		add_edge(i,n-1,(1<<(i-2)));
	}
	int s=1;
	for(int i=2;i<n-1&&s<r;i++){
		if((1<<(i-2))+s<=r){
			for(int k=s;k<(1<<(i-2))+s;k++){
				p_len=0;
				p[++p_len]=1;
				for(int j=2;j<n-1;j++){
					if((k>>(j-2))&1){
						p[++p_len]=j;
					}
				}
				p[++p_len]=n-1;
				int sum=0;
				for(int j=2;j<=p_len;j++){
					sum+=mp[p[j-1]][p[j]];
				}
				for(int j=2;j<=p_len;j++){
					if(mp[p[j-1]][p[j]]==0){
						add_edge(p[j-1],p[j],k+1-sum);
						break;
					}
				}
			}
			s+=(1<<(i-2));
		}
		else{
			s++;
			add_edge(1,i,1);
			for(int k=i-1;k>1;k--){
				if(((r-s)>>(k-2))&1){
					int sum=mp[i][n-1];
					add_edge(k,i,s-sum);
					s+=(1<<(k-2));
				}
			}
			break;
		}
	}
	/*for(int i=1;i<r;i++){
		p_len=0;
		p[++p_len]=1;
		for(int j=2;j<n-1;j++){
			if((i>>(j-2))&1){
				p[++p_len]=j;
			}
		}
		p[++p_len]=n-1;
		int sum=0;
		for(int j=2;j<=p_len;j++){
			sum+=mp[p[j-1]][p[j]];
		}
		for(int j=2;j<=p_len;j++){
			if(mp[p[j-1]][p[j]]==0){
				add_edge(p[j-1],p[j],i+1-sum);
				break;
			}
		}
	}*/
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
	}
	return 0;
}