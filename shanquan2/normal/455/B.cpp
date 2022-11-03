#include<cstdio>
#include<cstring>
using namespace std;

struct node{
	int son[26];
}trie[100001];
bool win[100001],lose[100001];
void dfs(int x){
	bool f=1;
	for(int i=0;i<26;i++)
		if(trie[x].son[i]!=-1){
			f=0;
			dfs(trie[x].son[i]);
			win[x]|=!win[trie[x].son[i]];
			lose[x]|=!lose[trie[x].son[i]];
		}
	if(f)win[x]=0,lose[x]=1;
	return;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int top=1;
	memset(trie[0].son,-1,sizeof(trie[0].son));
	for(int i=0;i<n;i++){
		char ch[100001];scanf("%s",ch);
		int now=0;
		for(int j=0;j<strlen(ch);j++)
			if(trie[now].son[ch[j]-'a']!=-1)
				now=trie[now].son[ch[j]-'a'];
			else{
				trie[now].son[ch[j]-'a']=top;
				memset(trie[top].son,-1,sizeof(trie[top].son));
				now=top;
				top++;
			}
	}
	dfs(0);
	if(!win[0])printf("Second\n");
	if(win[0]&&lose[0])printf("First\n");
	if(win[0]&&!lose[0])
		if(k%2)printf("First\n");else printf("Second\n");
	return 0;
}