#include <cstdio>
int a[20];
int num[15];
int ans[1005];
int main(){
	int n;
	scanf("%d",&n);
	int now;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		switch(a[i]){
			case 9:num[3]+=2;
			case 8:num[2]+=3;
			case 7:num[7]++;
			case 6:num[2]++,num[3]++;
			case 5:num[5]++;
			case 4:num[2]+=2;
			case 3:num[3]++;
			case 2:num[2]++;
		}
	}
	for(int i=7;i>=2;i--){
		if(num[i]>0){
			ans[i]=num[i];
			for(int j=i-1;j>=2;j--){
				if(j==6){
					num[2]-=num[i];
					num[3]-=num[i];
				}
				if(j==5){
					num[5]-=num[i];
				}
				if(j==4){
					num[2]-=2*num[i];
				}
				if(j==3){
					num[3]-=num[i];
				}
				if(j==2){
					num[2]-=num[i];
				}
			}
			num[i]=0;
		}
	}
	for(int i=7;i>=2;i--){
		if(ans[i]>0){
			for(int j=1;j<=ans[i];j++){
				printf("%d",i);
			}
		}
	}
	puts("");
	return 0;
}