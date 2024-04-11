#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int pos_x=0,pos_y=0;
	printf("%d\n",(n+1)*3+1);
	for(int i=1;i<=n+1;i++){
		printf("%d %d\n",pos_x,pos_y);
		printf("%d %d\n",pos_x,pos_y+1);
		printf("%d %d\n",pos_x+1,pos_y);
		pos_x++,pos_y++;
	}
	printf("%d %d\n",pos_x,pos_y);
	return 0;
}