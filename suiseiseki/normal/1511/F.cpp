#include <queue>
#include <cstdio>
#include <algorithm>
const int Maxn=200;
const int Maxl=40;
const int Mod=998244353;
int n,m;
namespace Trie{
	struct Trie_Node{
		int ch[26];
		bool pos;
	}node[Maxl+5];
	int id_tot;
	void insert(char *s,int len){
		int root=0;
		for(int i=1;i<=len;i++){
			if(node[root].ch[s[i]-'a']==0){
				node[root].ch[s[i]-'a']=++id_tot;
			}
			root=node[root].ch[s[i]-'a'];
		}
		node[root].pos=1;
	}
}
struct Node{
	int id,x,y;
	Node(int _id=0,int _x=0,int _y=0){
		id=_id,x=_x,y=_y;
	}
};
std::queue<Node> q;
int id[Maxl+5][Maxl+5],id_tot;
int get_id(int x,int y){
	if(x>y){
		std::swap(x,y);
	}
	if(id[x][y]==0){
		id[x][y]=++id_tot;
		q.push(Node(id[x][y],x,y));
	}
	return id[x][y];
}
struct Matrix{
	int a[Maxn+5][Maxn+5];
	void init(){
		for(int i=1;i<=id_tot;i++){
			for(int j=1;j<=id_tot;j++){
				a[i][j]=0;
			}
		}
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		ans.init();
		for(int i=1;i<=id_tot;i++){
			for(int k=1;k<=id_tot;k++){
				for(int j=1;j<=id_tot;j++){
					ans.a[i][j]=(ans.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%Mod;
				}
			}
		}
		return ans;
	}
}g;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		static char s[Maxl+5];
		scanf("%s",s+1);
		int len=0;
		while(s[++len]!='\0');
		len--;
		Trie::insert(s,len);
	}
	get_id(0,0);
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int a=Trie::node[u.x].ch[i],b=Trie::node[u.y].ch[i];
			if(a==0||b==0){
				continue;
			}
			g.a[u.id][get_id(a,b)]++;
			if(Trie::node[a].pos){
				g.a[u.id][get_id(0,b)]++;
			}
			if(Trie::node[b].pos){
				g.a[u.id][get_id(a,0)]++;
			}
			if(Trie::node[a].pos&&Trie::node[b].pos){
				g.a[u.id][get_id(0,0)]++;
			}
		}
	}
	Matrix ans;
	ans.init();
	for(int i=1;i<=id_tot;i++){
		ans.a[i][i]=1;
	}
	while(m){
		if(m&1){
			ans=ans*g;
		}
		g=g*g;
		m>>=1;
	}
	printf("%d\n",ans.a[1][1]);
	return 0;
}