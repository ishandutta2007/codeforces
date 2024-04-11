#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=400000;
const int Maxm=20000000;
int n;
int a[Maxn+5];
int num[Maxm<<1|5];
int sum[Maxm<<1|5];
int find_sum(int left,int right){
	if(left==0){
		return sum[right];
	}
	return sum[right]-sum[left-1];
}
int main(){
	read(n);
	int num_0=0,num_1=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		num[a[i]]++;
		if(a[i]&1){
			num_1++;
		}
		else{
			num_0++;
		}
	}
	int ans=(((num_0)&1)&(num_1&1));
	/*for(int i=0;i<=Maxm;i++){
		if(num[i]>1){
			if((num[i]>>1)&1){
				ans^=(i+i);
			}
			num[i]&=1;
		}
	}*/
	for(int i=25;i>1;i--){
		sum[0]=num[0];
		for(int j=1;j<=(1<<i);j++){
			sum[j]=sum[j-1]+num[j];
		}
		int now=0;
		for(int j=0;j<(1<<i);j++){
			if(num[j]){
				if(j<(1<<(i-1))){
					now^=(num[j]&1)&(find_sum((1<<(i-1)),(1<<i)-j-1)&1);
					now^=(num[j]&1)&(find_sum(max((1<<(i-1))-j,j+1),(1<<(i-1))-1)&1);
					if(num[j]>1){
						if((j>>(i-2))&1){
							now^=(1ll*num[j]*(num[j]-1)/2)&1;
						}
					}
				}
				else{
					now^=(num[j]&1)&(find_sum(max((1<<i)-(j-(1<<(i-1))),j+1),(1<<i)-1)&1);
					if(num[j]>1){
						if((j>>(i-2))&1){
							now^=(1ll*num[j]*(num[j]-1)/2)&1;
						}
					}
				}
			}
		}
		ans^=(now<<(i-1));
		for(int j=0;j<(1<<(i-1));j++){
			num[j]+=num[j+(1<<(i-1))];
		}
	}
	printf("%d\n",ans);
	return 0;
}