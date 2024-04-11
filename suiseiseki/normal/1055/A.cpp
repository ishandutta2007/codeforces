#include <cstdio>
int a[1005],b[1005];
bool visit[1005];
bool use[1005];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	bool change=1;
	visit[1]=1;
	while(change&&!visit[s]){
		change=0;
		for(int i=1;i<=n;i++){
			if(visit[i]&&!use[i]){
				use[i]=1;
				if(a[i]){
					for(int j=i+1;j<=n;j++){
						if(a[j]){
							if(!visit[j]){
								change=1;
							}
							visit[j]=1;
						}
					}
				}
				if(b[i]){
					for(int j=i-1;j>0;j--){
						if(b[j]){
							if(!visit[j]){
								change=1;
							}
							visit[j]=1;
						}
					}
				}
			}
		}
	}
	if(visit[s]){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}