#include <cstdio>
const int Maxn=100000;
char s[Maxn+5],t[Maxn+5];
int n,m;
int nxt[Maxn+5][26];
void solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=m=0;
	while(s[++n]!='\0');
	n--;
	while(t[++m]!='\0');
	m--;
	if(m>n){
		puts("NO");
		return;
	}
	for(int i=0;i<26;i++){
		nxt[n][i]=-1;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i+1]-'a']=i+1;
	}
	int pos=0;
	bool flag=1;
	for(int i=1;i<=m;i++){
		int nxt_pos=nxt[pos][t[i]-'a'];
		while(nxt_pos!=-1&&((nxt_pos-(pos==0?0:pos)-1)&1)){
			nxt_pos=nxt[nxt_pos][t[i]-'a'];
		}
		pos=nxt_pos;
		if(pos==-1){
			flag=0;
			break;
		}
	}
	if((n-pos)&1){
		flag=0;
	}
	if(flag){
		puts("YES");
		return;
	}
	pos=0;
	flag=1;
	for(int i=1;i<=m;i++){
		int nxt_pos=nxt[pos][t[i]-'a'];
		while(nxt_pos!=-1&&((nxt_pos-(pos==0?-1:pos)-1)&1)){
			nxt_pos=nxt[nxt_pos][t[i]-'a'];
		}
		pos=nxt_pos;
		if(pos==-1){
			flag=0;
			break;
		}
	}
	if((n-pos)&1){
		flag=0;
	}
	if(flag){
		puts("YES");
		return;
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}