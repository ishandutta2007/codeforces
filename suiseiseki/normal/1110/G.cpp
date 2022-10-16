#include<bits/stdc++.h>
using namespace std;
void read(int &a){
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=1000000;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
int deg[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
	deg[from]++;
}
int n;
char s[Maxn+5];
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=deg[i]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		scanf("%s",s+1);
		if(n<3){
			puts("Draw");
			continue;
		}
		if(n==3){
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=(s[i]=='W');
			}
			if(cnt>=2){
				puts("White");
			}
			else{
				puts("Draw");
			}
			continue;
		}
		bool flag=0;
		int tmp_n=n;
		for(int i=1;i<=tmp_n;i++){
			if(s[i]=='W'){
				n++;
				head[n]=0;
				add_edge(i,n);
				add_edge(n,i);
				deg[n]=3;
			}
		}
		int sum=0;
		for(int i=1;i<=n&&(!flag);i++){
			if(deg[i]>3){
				flag=1;
			}
			else if(deg[i]==3){
				int num=0;
				for(int j=head[i];j;j=nxt[j]){
					int v=arrive[j];
					if(deg[v]>=2){
						num++;
					}
				}
				if(num>=2){
					flag=1;
				}
				sum++;
			}
		}
		if(sum>=2&&(n&1)){
			flag=1;
		}
		if(flag){
			puts("White");
		}
		else{
			puts("Draw");
		}
	}
	return 0;
}