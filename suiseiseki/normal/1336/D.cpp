#include <cstdio>
using namespace std;
const int Maxn=100;
int ud[Maxn+5],vd[Maxn+5];
int t_1,t_2;
void ask(int pos,int &u,int &v){
	printf("+ %d\n",pos);
	fflush(stdout);
	int tmp_1,tmp_2;
	scanf("%d%d",&tmp_1,&tmp_2);
	u=tmp_1-t_1;
	v=tmp_2-t_2;
	t_1=tmp_1;
	t_2=tmp_2;
}
int x[Maxn+5];
int calc(int v){
	for(int i=1;;i++){
		if((i*(i-1)>>1)==v){
			return i;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%d%d",&t_1,&t_2);
	for(int i=2;i<n-1;i++){
		ask(i,ud[i],vd[i]);
	}
	int u_1,v_1,u_2,v_2,u_3,v_3;
	ask(n,u_1,v_1);
	ask(n-1,u_2,v_2);
	ask(n,u_3,v_3);
	x[n-2]=(v_3-v_1)-1;
	x[n]=calc(u_3)-1;
	x[n-1]=v_3/(x[n-2]+1)-1;
	x[n-3]=(v_2-1ll*(x[n]+1)*(x[n-2]+1))/(x[n-2]+1)-1;
	for(int i=n-4;i>0;i--){
		x[i]=(vd[i+2]-1ll*x[i+3]*(x[i+1]+1)-x[i+3]*x[i+4])/(x[i+1]+1)-1;
	}
	x[1]++;
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	puts("");
	fflush(stdout);
	return 0; 
}