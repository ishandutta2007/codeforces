#include <cstdio>
#include <cstring>
#define Maxn 100000
#define Mod 1000000007
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=(int)(1ll*ans*a%Mod);
		}
		b>>=1;
		a=(int)(1ll*a*a%Mod);
	}
	return ans;
}
struct Node{
	int a[Maxn<<1|5];
	void clear(){
		memset(a,-1,sizeof a);
	}
	Node(){
		memset(a,-1,sizeof a);
	}
	int grand(int x){
		return a[x]==-1?x:a[x]=grand(a[x]);
	}
	bool merge(int x,int y){
		int ga=grand(x),gb=grand(y);
		if(grand(x^1)==gb){
			return 0;
		}
		if(grand(y^1)==ga){
			return 0;
		}
		if(ga!=gb){
			a[ga]=gb;
		}
		return 1;
	}
	bool check(int a,int b,int t){
		if(t==0){
			return merge(a<<1,b<<1)&&merge(a<<1|1,b<<1|1);
		}
		else if(t==1){
			return merge(a<<1,b<<1|1)&&merge(a<<1|1,b<<1);
		}
		return 0;
	}
	int count(int n){
		n=(n<<1)+1;
		int ans=0;
		for(int i=0;i<=n;i++){
			if(grand(i)==i){
				ans++;
			}
		}
		return ans;
	}
}s;
void work(){
	int n,k,a,b,p;
	char ch[15];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a,&b);
		a--,b--;
		scanf("%s",ch);
		p=(ch[0]=='x'?0:1);
		int l=ab(a-b);
		int r=mn(a+b,((n-1)<<1)-(a+b));
		if(!s.check(l,r+2,p)){
			puts("0");
			return;
		}
	}
	int cnt=s.count(n+1);
	printf("%d\n",ksm(2,(cnt-4)>>1));
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int a,b;
	char qu[5];
	int now;
	int left,right;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		scanf("%s",qu);
		now=((*qu)=='x'?0:1);
		left=ab(a-b);
		right=mn(a+b,((n-1)<<1)-a-b);
		if(!s.check(left,right+2,now)){
			puts("0");
			return 0;
		}
	}
	int cnt=s.count(n+1);
	printf("%d\n",ksm(2,(cnt-4)>>1));
	return 0;
}