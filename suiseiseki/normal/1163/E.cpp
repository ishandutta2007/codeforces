#include <cstdio>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
const int Maxn=400000;
int n;
int s[Maxn+5];
int a[35],v[35];
void add(int x){
	int tmp=x;
	for(int i=30;i>=0;i--){
		if((x>>i)&1){
			if(a[i]==0){
				a[i]=x;
				v[i]=tmp;
				break;
			}
			if(v[i]>tmp){
				swap(a[i],x);
				swap(v[i],tmp);
			}
			x^=a[i];
		}
	}
}
int len;
int p[Maxn+5];
void dfs(int x){
	if(x<0){
		return;
	}
	dfs(x-1);
	p[++len]=v[x];
	dfs(x-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		add(s[i]);
	}
	if(a[0]==0){
		puts("0");
		puts("0");
		return 0;
	}
	for(int i=0;i<=30;i++){
		if(a[i]==0){
			bool unable=1;
			while(unable){
				i--;
				int maxn=(1<<(i+1));
				unable=0;
				for(int j=0;j<=i;j++){
					if(v[j]>=maxn){
						unable=1;
						break;
					}
				}
			}
			printf("%d\n",i+1);
			dfs(i);
			int val=0;
			for(int j=0;j<=len;j++){
				val^=p[j];
				printf("%d ",val);
			}
			puts("");
			break;
		}
	}
	return 0;
}