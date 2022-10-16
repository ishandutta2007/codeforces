#include <cstdio>
const int Maxn=16;
int query(int x,int y){
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
bool answer(int x,int y){
	printf("DIG %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	int val_1=query(1,1),val_2=query(1,m);
	val_1+=4;
	val_2+=2,val_2-=m*2;
	int sum_x=(val_1+val_2)/2,sum_y=(val_1-val_2)/2;
	int val_3=query(sum_x/2,1);
	val_3+=2,val_3-=sum_y;
	int val_4=query(1,sum_y/2);
	val_4+=2,val_4-=sum_x;
	int x_1=(sum_x-val_3)/2,x_2=(sum_x+val_3)/2,y_1=(sum_y-val_4)/2,y_2=(sum_y+val_4)/2;
	if(answer(x_1,y_1)){
		answer(x_2,y_2);
	}
	else{
		answer(x_1,y_2);
		answer(x_2,y_1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}