#include <cstdio>
typedef long long ll;
const int Maxn=1000000;
char s[Maxn+5];
int len;
namespace SAM{
	struct Node{
		int ch[26];
		int len,fa;
		int cnt;
	}node[Maxn<<1|5];
	int id_tot=1,last=1;
	int deg[Maxn<<1|5];
	int qu[Maxn<<1|5],qu_f,qu_t;
	void add_ch(int val){
		int p=last;
		int np=last=++id_tot;
		node[np].len=node[p].len+1;
		node[np].cnt=1;
		for(;p&&node[p].ch[val]==0;p=node[p].fa){
			node[p].ch[val]=np;
		}
		if(p==0){
			node[np].fa=1;
		}
		else{
			int q=node[p].ch[val];
			if(node[q].len==node[p].len+1){
				node[np].fa=q;
			}
			else{
				int nq=++id_tot;
				node[nq]=node[q];
				node[nq].cnt=0;
				node[nq].len=node[p].len+1;
				node[q].fa=node[np].fa=nq;
				for(;p&&node[p].ch[val]==q;p=node[p].fa){
					node[p].ch[val]=nq;
				}
			}
		}
	}
	void init(){
		for(int i=2;i<=id_tot;i++){
			deg[node[i].fa]++;
		}
		qu_f=1,qu_t=0;
		for(int i=1;i<=id_tot;i++){
			if(deg[i]==0){
				qu[++qu_t]=i;
			}
		}
		while(qu_f<=qu_t){
			int u=qu[qu_f++];
			node[node[u].fa].cnt+=node[u].cnt;
			deg[node[u].fa]--;
			if(deg[node[u].fa]==0){
				qu[++qu_t]=node[u].fa;
			}
		}
	}
}
bool vis[Maxn<<1|5];
int lis[Maxn<<1|5],lis_len;
int main(){
	scanf("%s",s+1);
	while(s[++len]!='\0');
	len--;
	for(int i=1;i<=len;i++){
		SAM::add_ch(s[i]-'a');
	}
	SAM::init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		len=0;
		while(s[++len]!='\0');
		len--;
		int root=1,l=0;
		ll ans=0;
		for(int j=1;j<=len;j++){
			while(root!=1&&SAM::node[root].ch[s[j]-'a']==0){
				root=SAM::node[root].fa;
				l=SAM::node[root].len;
			}
			if(SAM::node[root].ch[s[j]-'a']){
				root=SAM::node[root].ch[s[j]-'a'];
				l++;
			}
		}
		lis_len=0;
		for(int j=1;j<=len;j++){
			if(l==len&&!vis[root]){
				vis[root]=1;
				ans+=SAM::node[root].cnt;
				lis[++lis_len]=root;
			}
			if(l>=len){
				l--;
				if(l==SAM::node[SAM::node[root].fa].len){
					root=SAM::node[root].fa;
				}
			}
			while(root!=1&&SAM::node[root].ch[s[j]-'a']==0){
				root=SAM::node[root].fa;
				l=SAM::node[root].len;
			}
			if(SAM::node[root].ch[s[j]-'a']){
				root=SAM::node[root].ch[s[j]-'a'];
				l++;
			}
		}
		for(int j=1;j<=lis_len;j++){
			vis[lis[j]]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}