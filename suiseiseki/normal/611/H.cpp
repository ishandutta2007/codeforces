#include <cstdio>
const int Maxn=200000;
int a[10][10];
int num[10];
int pow_10[10]={0,1,10,100,1000,10000,100000,1000000,10000000};
int get_len(int x){
	int ans=0;
	while(x){
		ans++;
		x/=10;
	}
	return ans;
}
int n;
bool check(){
	for(int i=1;i<(1<<6);i++){
		int num_node=0,num_edge=0;
		for(int j=1;j<=6;j++){
			if((i>>(j-1))&1){
				num_node+=num[j];
				for(int k=1;k<=6;k++){
					if((i>>(k-1))&1){
						num_edge+=a[j][k];
					}
				}
			}
		}
		if(num_node==0){
			continue;
		}
		if(num_edge>=num_node){
			return 0;
		}
	}
	return 1;
}
bool get_edge(){
	for(int u=1;u<=6;u++){
		for(int v=1;v<=6;v++){
			if(a[u][v]){
				if(num[u]>1){
					num[u]--,a[u][v]--;
					if(check()){
						printf("%d %d\n",pow_10[u]+num[u],pow_10[v]);
						return 1;
					}
					num[u]++,a[u][v]++;
				}
				if(num[v]>1){
					num[v]--,a[u][v]--;
					if(check()){
						printf("%d %d\n",pow_10[v]+num[v],pow_10[u]);
						return 1;
					}
					num[v]++,a[u][v]++;
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num[get_len(i)]++;
	}
	for(int i=1;i<n;i++){
		static char s_1[10],s_2[10];
		scanf("%s%s",s_1,s_2);
		int len_1=0,len_2=0;
		while(s_1[len_1++]!='\0');
		len_1--;
		while(s_2[len_2++]!='\0');
		len_2--;
		a[len_1][len_2]++;
	}
	if(!check()){
		puts("-1");
		return 0;
	}
	while(get_edge());
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			if(a[i][j]){
				printf("%d %d\n",pow_10[i]+num[i]-1,pow_10[j]+num[j]-1);
			}
		}
	}
	return 0;
}