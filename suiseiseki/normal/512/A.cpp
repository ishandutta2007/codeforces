#include <cstdio>
int head[26],arrive[105],nxt[105],tot;
int in[26];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
	in[to]++;
}
char s[2][105];
char ans[26];
bool visit[26];
bool if_cannot;
void find(char *s1,char *s2){
	int len_1=0,len_2=0;
	while(s1[++len_1]!='\0');
	while(s2[++len_2]!='\0');
	len_1--,len_2--;
	for(int i=1;i<=len_1&&i<=len_2;i++){
		if(s1[i]!=s2[i]){
			add_edge(s1[i]-'a',s2[i]-'a');
			return;
		}
	}
	if(len_1>len_2){
		if_cannot=1;
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s[0]+1);
	for(int i=1;i<n;i++){
		scanf("%s",s[i&1]+1);
		find(s[(i-1)&1],s[i&1]);
		if(if_cannot){
			puts("Impossible");
			return 0;
		}
	}
	int len=0;
	int tmp;
	for(int i=0;i<26;i++){
		tmp=-1;
		for(int j=0;j<26;j++){
			if(!visit[j]&&in[j]==0){
				tmp=j;
				break;
			}
		}
		if(tmp==-1){
			puts("Impossible");
			return 0;
		}
		ans[len++]=tmp+'a';
		visit[tmp]=1;
		for(int i=head[tmp];i;i=nxt[i]){
			in[arrive[i]]--;
		}
	}
	for(int i=0;i<26;i++){
		putchar(ans[i]);
	}
	puts("");
	return 0;
}