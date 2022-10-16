#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=300000;
const int Maxl=1000000;
char s[Maxl+5];
int x[Maxn+5],y[Maxn+5],len[Maxn+5];
int n;
int ans_x,ans_y;
bool check(int len){
	int min_x=0,min_y=0,max_x=(Maxl<<1),max_y=(Maxl<<1);
	int min_z=(-(Maxl<<1)),max_z=(Maxl<<1);
	for(int i=1;i<=n;i++){
		int x_1=max(0,x[i]-len),y_1=max(0,y[i]-len);
		int x_2=x[i]+len,y_2=y[i]+len;
		min_x=max(min_x,x_1);
		min_y=max(min_y,y_1);
		max_x=min(max_x,x_2);
		max_y=min(max_y,y_2);
		min_z=max(min_z,x[i]-y[i]-len);
		max_z=min(max_z,x[i]-y[i]+len);
	}
	if(min_x>max_x||min_y>max_y||min_z>max_z){
		return 0;
	}
	for(int i=min_y;i<=max_y;i++){
		if(min_x-i>=min_z&&min_x-i<=max_z){
			if(min_x!=0||i!=0){
				ans_x=min_x;
				ans_y=i;
				return 1;
			}
		}
		if(max_x-i>=min_z&&max_x-i<=max_z){
			if(max_x!=0||i!=0){
				ans_x=max_x;
				ans_y=i;
				return 1;
			}
		}
	}
	for(int i=min_x;i<=max_x;i++){
		if(i-min_y>=min_z&&i-min_y<=max_z){
			if(min_y!=0||i!=0){
				ans_x=i;
				ans_y=min_y;
				return 1;
			}
		}
		if(i-max_y>=min_z&&i-max_y<=max_z){
			if(max_y!=0||i!=0){
				ans_x=i;
				ans_y=max_y;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		while(s[++len[i]]!='\0');
		len[i]--;
		for(int j=1;j<=len[i];j++){
			if(s[j]=='B'){
				x[i]++;
			}
			else{
				y[i]++;
			}
		}
	}
	int left=0,right=(Maxl>>1);
	while(left<right){
		int mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	check(left);
	printf("%d\n",left);
	for(int i=1;i<=ans_x;i++){
		putchar('B');
	}
	for(int i=1;i<=ans_y;i++){
		putchar('N');
	}
	puts("");
	return 0;
}