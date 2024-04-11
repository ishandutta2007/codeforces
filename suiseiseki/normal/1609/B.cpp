#include <cstdio>
const int Maxn=100000;
int n,q;
char s[Maxn+5];
int get_num(int x){
	int ans=0;
	if(x-2>0){
		if(s[x-2]=='a'&&s[x-1]=='b'&&s[x]=='c'){
			ans++;
		}
	}
	if(x-1>0&&x+1<=n){
		if(s[x-1]=='a'&&s[x]=='b'&&s[x+1]=='c'){
			ans++;
		}
	}
	if(x+2<=n){
		if(s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c'){
			ans++;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=get_num(i);
	}
	ans/=3;
	for(int i=1;i<=q;i++){
		int pos;
		char op[4];
		scanf("%d",&pos);
		scanf("%s",op);
		ans-=get_num(pos);
		s[pos]=(*op);
		ans+=get_num(pos);
		printf("%d\n",ans);
	}
	return 0;
}