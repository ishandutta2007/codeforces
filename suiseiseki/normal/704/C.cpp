#include <cstdio>
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
template<typename Elem>
Elem abs(Elem a){
	return a<0?-a:a;
}
template<typename Elem>
void swap(Elem& a,Elem& b){
	Elem t=a;
	a=b;
	b=t;
}
const int Maxn=100000;
const int Mod=1000000007;
int id[Maxn+5],sign[Maxn+5],deg[Maxn+5],vis[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
int num[Maxn+5];
void unuse_add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
void add_edge(int u,int v,int w){
	unuse_add_edge(u,v,w);
	unuse_add_edge(v,u,w);
	deg[u]++;
	deg[v]++;
}
int rev[Maxn+5];
int sta[Maxn+5];
int top;
void dfs(int u){
	sta[++top]=u;
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis[v]){
			continue;
		}
		rev[top]=val[i];
		dfs(v);
	}
}
int res[2];
int main(){
	int n,m;
	read(m),read(n);
	int c_0=0,c_1=0;
	for(int i=1;i<=m;i++){
		int k,x,y;
		read(k);
		if(k==2){
			read(x),read(y);
		}
		else{
			read(x);
		}
		num[i]=k;
		if(k==2){
			if(x==y){
				c_0++;
				vis[i]=1;
				id[abs(x)]=i;
				continue;
			}
			if(x==-y){
				c_1++;
				vis[i]=1;
				id[abs(x)]=i;
				continue;
			}
		}
		if(id[abs(x)]){
			add_edge(i,id[abs(x)],(x<0)^sign[abs(x)]);
		}
		else{
			id[abs(x)]=i;
			sign[abs(x)]=(x<0);
		}
		if(k==2){
			if(id[abs(y)]){
				add_edge(i,id[abs(y)],(y<0)^sign[abs(y)]);
			}
			else{
				id[abs(y)]=i;
				sign[abs(y)]=(y<0);
			}
		}
	}
	res[0]=1;
	while(c_0--){
		res[0]=res[1]=(res[0]+res[1])%Mod;
	}
	while(c_1--){
		res[0]=(res[0]<<1)%Mod;
		res[1]=(res[1]<<1)%Mod;
		swap(res[0],res[1]);
	}
	int mul=1;
	for(int i=1;i<=n;i++){
		if(!id[i]){
			mul=(mul<<1)%Mod;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i]){
			continue;
		}
		if(!deg[i]){
			vis[i]=1;
			if(num[i]==1){
				res[0]=res[1]=(res[0]+res[1])%Mod;
			}
			else{
				int tr_0=(res[0]+3ll*res[1])%Mod;
				int tr_1=(3ll*res[0]+res[1])%Mod;
				res[0]=tr_0;
				res[1]=tr_1;
			}
		}
		if(deg[i]==1){
			top=0;
			dfs(i);
			int r_0=1,r_1=0,r_2=0,r_3=0;
			if(num[sta[1]]==2){
				r_2=1;
			}
			for(int j=1;j<top;j++){
				int tr_0,tr_1,tr_2,tr_3;
				if(rev[j]){
					tr_0=(r_1+r_3)%Mod;
					tr_1=(r_0+r_2)%Mod;
					tr_2=(r_0+r_3)%Mod;
					tr_3=(r_1+r_2)%Mod;
				}
				else{
					tr_0=(r_0+r_3)%Mod;
					tr_1=(r_1+r_2)%Mod;
					tr_2=(r_1+r_3)%Mod;
					tr_3=(r_0+r_2)%Mod;
				}
				r_0=tr_0;
				r_1=tr_1;
				r_2=tr_2;
				r_3=tr_3;
			}
			if(num[sta[top]]==2){
				r_2=(r_2+(r_0+r_2)%Mod)%Mod;
				r_3=(r_3+(r_1+r_3)%Mod)%Mod;
			}
			r_0=(r_0+r_3)%Mod;
			r_1=(r_1+r_2)%Mod;
			int tr_0=(1ll*r_0*res[0]+1ll*r_1*res[1])%Mod;
			int tr_1=(1ll*r_1*res[0]+1ll*r_0*res[1])%Mod;
			res[0]=tr_0;
			res[1]=tr_1;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i]){
			continue;
		}
		top=0;
		dfs(i);
		int R_0=0,R_1=0;
		int r_0,r_1,r_2,r_3;
		int Val=0;
		for(int j=head[sta[1]];j;j=nxt[j]){
			int v=arrive[j];
			if(v==sta[top]){
				Val=val[j];
			}
		}
		r_0=1;
		r_1=r_2=r_3=0;
		for(int j=1;j<top;j++){
			int tr_0,tr_1,tr_2,tr_3;
			if(rev[j]){
				tr_0=(r_1+r_3)%Mod;
				tr_1=(r_0+r_2)%Mod;
				tr_2=(r_0+r_3)%Mod;
				tr_3=(r_1+r_2)%Mod;
			}
			else{
				tr_0=(r_0+r_3)%Mod;
				tr_1=(r_1+r_2)%Mod;
				tr_2=(r_1+r_3)%Mod;
				tr_3=(r_0+r_2)%Mod;
			}
			r_0=tr_0;
			r_1=tr_1;
			r_2=tr_2;
			r_3=tr_3;
		}
		if(Val){
			R_0=(r_1+r_3)%Mod;
			R_1=(r_0+r_2)%Mod;
		}
		else{
			R_0=(r_0+r_3)%Mod;
			R_1=(r_1+r_2)%Mod;
		}
		r_0=r_1=r_3=0;
		r_2=1;
		for(int j=1;j<top;j++){
			int tr_0,tr_1,tr_2,tr_3;
			if(rev[j]){
				tr_0=(r_1+r_3)%Mod;
				tr_1=(r_0+r_2)%Mod;
				tr_2=(r_0+r_3)%Mod;
				tr_3=(r_1+r_2)%Mod;
			}
			else{
				tr_0=(r_0+r_3)%Mod;
				tr_1=(r_1+r_2)%Mod;
				tr_2=(r_1+r_3)%Mod;
				tr_3=(r_0+r_2)%Mod;
			}
			r_0=tr_0;
			r_1=tr_1;
			r_2=tr_2;
			r_3=tr_3;
		}
		if(Val){
			R_0=(R_0+(r_0+r_3)%Mod)%Mod;
			R_1=(R_1+(r_1+r_2)%Mod)%Mod;
		}
		else{
			R_0=(R_0+(r_1+r_3)%Mod)%Mod;
			R_1=(R_1+(r_0+r_2)%Mod)%Mod;
		}
		int tr_0=(1ll*R_0*res[0]+1ll*R_1*res[1])%Mod;
		int tr_1=(1ll*R_1*res[0]+1ll*R_0*res[1])%Mod;
		res[0]=tr_0;
		res[1]=tr_1;
	}
	printf("%d\n",(int)(1ll*res[1]*mul%Mod));
	return 0;
}