#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=1000;
const int Maxd=50;
const int Mod=1000000007;
struct Node{
	int ch[10];
	int dep,fail;
}node[Maxn*Maxd+5];
int id_tot;
char s[Maxn+5],x[Maxn+5],y[Maxn+5];
int n,d;
void add(char *s,int len){
	int root=0;
	for(int i=1;i<=len;i++){
		if(node[root].ch[s[i]]==0){
			node[root].ch[s[i]]=++id_tot;
			node[id_tot].dep=node[root].dep+1;
		}
		root=node[root].ch[s[i]];
	}
}
void init_bfs(){
	queue<int> q;
	for(int i=0;i<10;i++){
		if(node[0].ch[i]){
			q.push(node[0].ch[i]);
			node[node[0].ch[i]].fail=0;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			if(node[u].ch[i]==0){
				node[u].ch[i]=node[node[u].fail].ch[i];
			}
			else{
				node[node[u].ch[i]].fail=node[node[u].fail].ch[i];
				q.push(node[u].ch[i]);
			}
		}
	}
}
int f[Maxd+5][Maxn*Maxd+5][2][2];
int calc(char *s,int len){
	memset(f,0,sizeof f);
	f[0][0][1][0]=1;
	for(int i=0;i<len;i++){
		for(int j=0;j<=id_tot;j++){
			for(int a=0;a<=1;a++){
				for(int b=0;b<=1;b++){
					if(f[i][j][a][b]==0){
						continue;
					}
					for(int k=0;k<10;k++){
						if(a==1&&k>s[i+1]){
							break;
						}
						int &tmp=f[i+1][node[j].ch[k]][a&(k==s[i+1])][b|(node[node[j].ch[k]].dep==(len>>1))];
						tmp=(tmp+f[i][j][a][b])%Mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=id_tot;i++){
		ans=(ans+f[len][i][1][1])%Mod;
		ans=(ans+f[len][i][0][1])%Mod;
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	scanf("%s",x+1);
	while(x[++d]!='\0');
	d--;
	scanf("%s",y+1);
	for(int i=1;i<=n;i++){
		s[i]-='0';
	}
	for(int i=1;i<=d;i++){
		x[i]-='0';
		y[i]-='0';
	}
	for(int i=1;i<=(n-(d>>1)+1);i++){
		add(s+i-1,d>>1);
	}
	init_bfs();
	x[d]--;
	int tmp=d;
	while(x[tmp]<0){
		x[tmp-1]--;
		x[tmp]=9;
		tmp--;
	}
	printf("%d\n",(calc(y,d)-calc(x,d)+Mod)%Mod);
	return 0;
}