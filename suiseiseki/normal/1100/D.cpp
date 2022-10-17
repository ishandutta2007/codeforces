#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000
struct Car{
	int x,y;
}a[Maxn+5];
const int n=666;
int x,y;
bool mp[Maxn+5][Maxn+5];
void ask(int t_x,int t_y){
	x+=t_x;
	y+=t_y;
	if(mp[x][y]){
		y-=t_y;
	}
	cout<<x<<" "<<y<<endl;
	int k,nx,ny;
	scanf("%d%d%d",&k,&nx,&ny);
	if(k==-1){
		exit(0);
	}
	mp[a[k].x][a[k].y]=0;
	a[k].x=nx;
	a[k].y=ny;
	mp[a[k].x][a[k].y]=1;
}
int main(){
	fflush(stdout);
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		mp[a[i].x][a[i].y]=1;
	}
	while(x>500){
		ask(-1,0);
	}
	while(y>500){
		ask(0,-1);
	}
	while(x<500){
		ask(1,0);
	}
	while(y<500){
		ask(0,1);
	}
	int cnt_1=0,cnt_2=0,cnt_3=0,cnt_4=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>500||a[i].y>500){
			cnt_1++;
		}
		if(a[i].x<500||a[i].y>500){
			cnt_2++;
		}
		if(a[i].x>500||a[i].y<500){
			cnt_3++;
		}
		if(a[i].x<500||a[i].y<500){
			cnt_4++;
		}
	}
	if(cnt_1>=500){
		while(1){
			ask(1,1);
		}
	}
	else if(cnt_2>=500){
		while(1){
			ask(-1,1);
		}
	}
	else if(cnt_3>=500){
		while(1){
			ask(1,-1);
		}
	}
	else{
		while(1){
			ask(-1,-1);
		}
	}
	return 0;
}