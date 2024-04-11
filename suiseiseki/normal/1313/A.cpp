#include <cstdio>
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	int t;
	int a,b,c;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		if(a>0){
			a--;
			ans++;
		}
		if(b>0){
			b--;
			ans++;
		}
		if(c>0){
			c--;
			ans++;
		}
		if(a<b){
			swp(a,b);
		}
		if(b<c){
			swp(b,c);
		}
		if(a<b){
			swp(a,b);
		}
		if(a>0&&b>0){
			a--;
			b--;
			ans++;
		}
		if(b>0&&c>0){
			b--;
			c--;
			ans++;
		}
		if(a>0&&c>0){
			a--;
			c--;
			ans++;
		}
		if(a>0&&b>0&&c>0){
			a--;
			b--;
			c--;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}