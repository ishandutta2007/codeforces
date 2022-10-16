#include <ctime>
#include <cstdio>
#include <random>
using namespace std;
const int Maxn=(1<<18);
mt19937 rnd(time(NULL));
int num[Maxn+5];
int h,n;
int ask(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	scanf("%d",&h);
	n=(1<<h)-1;
	int T=420;
	while(T--){
		int x,y,z;
		x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
		while(x==y){
			y=rnd()%n+1;
		}
		while(x==z||y==z){
			z=rnd()%n+1;
		}
		num[ask(x,y,z)]++;
	}
	int mx_1=0,mx_2=0;
	for(int i=1;i<=n;i++){
		if(mx_1==0||num[i]>num[mx_1]){
			mx_2=mx_1;
			mx_1=i;
		}
		else if(mx_2==0||num[i]>num[mx_2]){
			mx_2=i;
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(i==mx_1||i==mx_2){
			continue;
		}
		if(ask(i,mx_1,mx_2)==i){
			ans=i;
			break;
		}
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}