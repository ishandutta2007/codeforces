#include <cstdio>
#define Hash_number 209
char s[500005],r[500005];
int n,d;
unsigned long long p[500005],hash[500005],rhash[500005];
bool ok(int ed,int d){
	ed++;
	int st=ed-d+1;
	if(st<0){
		return 1;
	}
	if((rhash[ed]-rhash[st-1]*p[d])*p[st-1]!=hash[ed]-hash[st-1]){
		return 1;
	}
	return 0;
}
bool dfs(int x,int t){
	if(x==n){
		puts(r);
		return 1;
	}
	for(r[x]=(t?s[x]:'a');r[x]<='z';r[x]++){
		hash[x+1]=hash[x]+r[x]*p[x];
		rhash[x+1]=rhash[x]*Hash_number+r[x];
		if(ok(x,d)&&ok(x,d+1)&&dfs(x+1,t&&(r[x]==s[x]))){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&d);
	scanf("%s",s);
	n=0;
	while(s[n++]!='\0');
	n--;
	int i=n-1;
	for(;i>=0&&s[i]=='z';i--){
		s[i]='a';
	}
	if(i<0){
		puts("Impossible");
		return 0;
	}
	s[i]++;
	p[0]=1;
	for(int i=1;i<n+100;i++){
		p[i]=p[i-1]*Hash_number;
	}
	if(!dfs(0,1)){
		puts("Impossible");
	}
	return 0;
}