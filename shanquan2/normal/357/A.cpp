#include<cstdio>
using namespace std;

int a[100];
int main(){
	int m;
	scanf("%d",&m);
	int s=0;
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]),s+=a[i];
	int x,y;
	scanf("%d%d",&x,&y);
	int s1=0;
	for(int i=0;i<m-1;i++){
		s1+=a[i];
		if(s1>=x && s1<=y && s-s1>=x && s-s1<=y){
			printf("%d\n",i+2);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}