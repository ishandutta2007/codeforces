#include <cstdio>
int a[200005];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int left=1,right=0;
	int q;
	char qu[3];
	int id;
	scanf("%d",&q);
	while(q--){
		scanf("%s",qu);
		scanf("%d",&id);
		if((*qu)=='L'){
			left--;
			a[id]=left;
		}
		else if((*qu)=='R'){
			right++;
			a[id]=right;
		}
		else{
			printf("%d\n",mn(a[id]-left,right-a[id]));
		}
	}
	return 0;
}