#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;


int main(){
	int x, y, t = 1, j;
	
	scanf("%d%d",&x,&y);
	
	while(y >= 2 && x*10+y >= 22){
		if(t){
			for(j = 0; j < 2 && x > j; j++);
			x -= j;
			y -= (2-j)*10+2;
		} else {
			for(j = 2; j < 22 && y >= j+10; j+=10);
			x -= (22-j)/10;
			y -= j;
		}
		t = (t+1)%2;
	}
	
	printf("%s\n",(t)?"Hanako":"Ciel");
	
	return 0;
}