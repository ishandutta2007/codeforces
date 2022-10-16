#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=2000;
const int Maxm=800;
const int Inf=0x3f3f3f3f;
int n;
char l_s[Maxm+5],r_s[Maxm+5];
int l_num[Maxm+5],r_num[Maxm+5];
int l_len,r_len;
struct Trie_Node{
	int ch[10];
	int fail;
}node[Maxm*20+5];
int g[Maxm*20+5][Maxn+5];
int id_tot;
int get_ch(int u,int c){
	if(node[u].ch[c]==0){
		node[u].ch[c]=++id_tot;
	}
	return node[u].ch[c];
}
void bfs_fail(){
	static int qu[Maxm*30+5],qu_f,qu_t;
	qu_f=1,qu_t=0;
	for(int i=0;i<10;i++){
		if(node[0].ch[i]){
			qu[++qu_t]=node[0].ch[i];
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=0;i<=n;i++){
			g[u][i]+=g[node[u].fail][i];
		}
		for(int i=0;i<10;i++){
			if(node[u].ch[i]){
				node[node[u].ch[i]].fail=node[node[u].fail].ch[i];
				qu[++qu_t]=node[u].ch[i];
			}
			else{
				node[u].ch[i]=node[node[u].fail].ch[i];
			}
		}
	}
	for(int i=0;i<=id_tot;i++){
		for(int j=1;j<=n;j++){
			g[i][j]+=g[i][j-1];
		}
	}
}
int f[Maxn+5][Maxm*20+5];
bool vis[Maxn+5][Maxm*20+5];
int lis[Maxn+5];
int main(){
	scanf("%s",l_s+1);
	scanf("%s",r_s+1);
	scanf("%d",&n);
	while(l_s[++l_len]!='\0');
	l_len--;
	while(r_s[++r_len]!='\0');
	r_len--;
	for(int i=1;i<=l_len;i++){
		l_num[i]=l_s[i]-'0';
	}
	for(int i=1;i<=r_len;i++){
		r_num[i]=r_s[i]-'0';
	}
	int root_l=0,root_r=0;
	if(l_len==r_len){
		for(int i=1;i<=l_len;i++){
			if(root_l==root_r){
				for(int j=l_num[i]+1;j<r_num[i];j++){
					g[get_ch(root_l,j)][l_len-i]++;
				}
				root_l=get_ch(root_l,l_num[i]);
				root_r=get_ch(root_r,r_num[i]);
			}
			else{
				for(int j=l_num[i]+1;j<10;j++){
					g[get_ch(root_l,j)][l_len-i]++;
				}
				for(int j=0;j<r_num[i];j++){
					g[get_ch(root_r,j)][r_len-i]++;
				}
				root_l=get_ch(root_l,l_num[i]);
				root_r=get_ch(root_r,r_num[i]);
			}
		}
		g[root_l][0]++;
		if(root_l!=root_r){
			g[root_r][0]++;
		}
	}
	else{
		for(int i=1;i<=l_len;i++){
			for(int j=l_num[i]+1;j<10;j++){
				g[get_ch(root_l,j)][l_len-i]++;
			}
			root_l=get_ch(root_l,l_num[i]);
		}
		for(int i=1;i<=r_len;i++){
			for(int j=0;j<r_num[i];j++){
				g[get_ch(root_r,j)][r_len-i]++;
			}
			root_r=get_ch(root_r,r_num[i]);
		}
		g[root_l][0]++,g[root_r][0]++;
		for(int i=l_len+1;i<r_len;i++){
			for(int j=1;j<10;j++){
				g[get_ch(0,j)][i-1]++;
			}
		}
	}
	node[0].ch[0]=0;
	bfs_fail();
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=id_tot;j++){
			if(f[i][j]<0){
				continue;
			}
			for(int k=0;k<10;k++){
				if(f[i][j]+g[j][n-i]>f[i+1][node[j].ch[k]]){
					f[i+1][node[j].ch[k]]=f[i][j]+g[j][n-i];
				}
			}
		}
	}
	int ans=-Inf;
	for(int i=0;i<=id_tot;i++){
		ans=std::max(ans,f[n][i]+g[i][0]);
	}
	printf("%d\n",ans);
	for(int i=0;i<=id_tot;i++){
		if(f[n][i]+g[i][0]==ans){
			vis[n][i]=1;
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=id_tot;j++){
			if(f[i][j]<0){
				continue;
			}
			for(int k=0;k<10;k++){
				if(vis[i+1][node[j].ch[k]]&&f[i][j]+g[j][n-i]==f[i+1][node[j].ch[k]]){
					vis[i][j]=1;
					break;
				}
			}
		}
	}
	for(int i=0,u=0;i<n;i++){
		for(int j=0;j<10;j++){
			if(vis[i+1][node[u].ch[j]]&&f[i][u]+g[u][n-i]==f[i+1][node[u].ch[j]]){
				u=node[u].ch[j];
				printf("%d",j);
				break;
			}
		}
	}
	puts("");
	return 0;
}