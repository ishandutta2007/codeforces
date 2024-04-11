#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 55
#define ll long long
int a[Maxn+5];
int len;
ll t;
int n;
struct Edge{
	int x_1,y_1,x_2,y_2;
}edge[305];
int e_len;
Edge make_edge(int x_1,int y_1,int x_2,int y_2){
	static Edge ans;
	ans.x_1=x_1;
	ans.x_2=x_2;
	ans.y_1=y_1;
	ans.y_2=y_2;
	return ans;
}
int x;
void del_1(){//delete 3
	edge[++e_len]=make_edge(x-1,x+1,x,x+1);
}
void del_2(){//delete 3
	edge[++e_len]=make_edge(x+1,x-1,x+1,x);
}
void del_3(){//delete 1
	edge[++e_len]=make_edge(x-1,x+2,x,x+2);
}
void del_4(){//delete 1
	edge[++e_len]=make_edge(x+2,x-1,x+2,x);
}
int main(){
	cin>>t;
	while(t){
		a[++len]=t%6ll;
		t/=6ll;
	}
	n=(len<<1)+2;
	edge[++e_len]=make_edge(1,2,2,2);
	edge[++e_len]=make_edge(2,1,2,2);
	for(int i=2,j=6;i<n&&j<n;i+=2,j+=2){
		edge[++e_len]=make_edge(i,j,i+1,j);
		edge[++e_len]=make_edge(i,j+1,i+1,j+1);
	}
	if(n>4){
		edge[++e_len]=make_edge(n-4,n,n-3,n);
	}
	for(int i=6,j=2;i<n&&j<n;i+=2,j+=2){
		edge[++e_len]=make_edge(i,j,i,j+1);
		edge[++e_len]=make_edge(i+1,j,i+1,j+1);
	}
	if(n>4){
		edge[++e_len]=make_edge(n,n-4,n,n-3);
	}
	for(int i=2;i+2<n;i+=2){
		edge[++e_len]=make_edge(i+2,i,i+3,i);
		edge[++e_len]=make_edge(i+2,i+1,i+3,i+1);
		edge[++e_len]=make_edge(i,i+2,i,i+3);
		edge[++e_len]=make_edge(i+1,i+2,i+1,i+3);
	}
	x=2;
	for(int i=len;i>0;i--){
		if(a[i]==0){
			del_1();
			del_2();
			del_3();
			del_4();
		}
		else if(a[i]==1){
			del_1();
			del_2();
			del_3();
		}
		else if(a[i]==2){
			del_1();
			del_2();
		}
		else if(a[i]==3){
			del_2();
			del_3();
			del_4();
		}
		else if(a[i]==4){
			del_2();
			del_4();
		}
		else{
			del_2();
		}
		x+=2;
	}
	printf("%d %d\n",n,n);
	printf("%d\n",e_len);
	for(int i=1;i<=e_len;i++){
		printf("%d %d %d %d\n",edge[i].x_1,edge[i].y_1,edge[i].x_2,edge[i].y_2);
	}
	return 0;
}