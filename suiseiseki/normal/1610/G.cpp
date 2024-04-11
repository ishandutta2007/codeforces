#include <cstdio>
const int Maxn=300000;
int n;
int a[Maxn+5];
int nxt[Maxn+5];
char s[Maxn+5];
bool check(int x,int y){
	while(x<=n&&y<=n&&s[x]==s[y]){
		x=nxt[x+1],y=nxt[y+1];
	}
	if(x<=n&&y<=n){
		return s[x]<=s[y];
	}
	return x>n&&y<=n;
}
bool cmp(int i,int j){
	while(i<=n&&j<=n&&s[i]==s[j])i=nxt[i+1],j=nxt[j+1];
	if(i<=n&&j<=n)return s[i]<=s[j];
	return i>n&&j<=n;	
}
int st[Maxn+5],st_top;
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	nxt[n+1]=n+1;
	st[++st_top]=n+1;
	for(int i=n;i>0;i--){
		nxt[i]=i;
		if(s[i]==')'){
			st[++st_top]=i;
		}
		else{
			st_top--;
			if(st_top==0){
				st[++st_top]=i;
			}
			else if(check(i,st[st_top])){
				st[st_top]=i;
			}
			else{
				nxt[i]=st[st_top];
			}
		}
	}
	for(int i=1;i<=n;i=nxt[i+1]){
		putchar(s[i]);
	}
	putchar('\n');
	return 0;
}