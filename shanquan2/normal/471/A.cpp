#include<cstdio>
using namespace std;

int main(){
	int a[6];
	for(int i=0;i<6;i++)scanf("%d",&a[i]);
	for(int i=0;i<6;i++){
		int cnt=0,e1=-1,e2;
		for(int j=0;j<6;j++)
			if(a[j]==a[i] && cnt<4)cnt++;
			else 
				if(e1==-1)e1=a[j];else e2=a[j];
		if(cnt>=4){
			if(e1==e2)printf("Elephant\n");
			else printf("Bear\n");
			return 0;
		}
	}
	printf("Alien\n");
	return 0;
}