#include <cstdio>
#define Maxn 2000
#define Maxm 500
char s1[Maxn+5],s2[Maxm+5];
int l1,l2,j,d[Maxn+5][Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
bool work(int i){
	int x=i,y=l2;
	while(x>0&&y>0){
		if(s1[x-1]==s2[y-1]){
			x--;
			y--;
		}
		else{
			x--;
		}
	}
	if(!y){
		j=x;
		return 1;
	}
	else{
		j=0;
		return 0;
	}
}
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	while(s1[l1++]!='\0');
	l1--;
	while(s2[l2++]!='\0');
	l2--;
	bool flag;
	for(int i=1;i<=l1;i++){
		flag=work(i);
		for(int k=0;k<=i;k++){
			d[i][k]=mx(d[i-1][k],d[i-1][k-1]);
			if(flag&&j>=k-i+j+l2&&k-i+j+l2>=0){
				d[i][k]=mx(d[i][k],d[j][k-(i-j-l2)]+1);
			}
		}
	}
	for (int i=0;i<=l1;i++){
		printf("%d ",d[l1][i]);
	}
	puts("");
	return 0;
}