#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int power[51],n,cnt;
int petasan[501][501];
bool dp[501][501][51][9];

void path(int x,int y,int z,int q){
	if(z>n)return;
	if(dp[x][y][z][q])return;
	if(z==1)rep(i,power[z])petasan[x-i+1][y]=1;
	dp[x][y][z][q]=1;
	if(z!=1)rep(i,power[z]){
		if(q==1)petasan[x+i][y]=1;		//1
		if(q==2)petasan[x][y+i]=1;		//2
		if(q==3)petasan[x-i][y]=1;		//3
		if(q==4)petasan[x][y-i]=1;		//4
		if(q==5)petasan[x+i][y+i]=1;	//5
		if(q==6)petasan[x+i][y-i]=1;	//6
		if(q==7)petasan[x-i][y+i]=1;	//7
		if(q==8)petasan[x-i][y-i]=1;	//8
	}if(z!=1){
		if(q==1){
			path(x+power[z],y,z+1,5);
			path(x+power[z],y,z+1,6);
		}
		if(q==2){
			path(x,y+power[z],z+1,5);
			path(x,y+power[z],z+1,7);
		}
		if(q==3){
			path(x-power[z],y,z+1,7);
			path(x-power[z],y,z+1,8);
		}
		if(q==4){
			path(x,y-power[z],z+1,8);
			path(x,y-power[z],z+1,6);
		}
		if(q==5){
			path(x+power[z],y+power[z],z+1,1);
			path(x+power[z],y+power[z],z+1,2);
		}
		if(q==6){
			path(x+power[z],y-power[z],z+1,1);
			path(x+power[z],y-power[z],z+1,4);
		}
		if(q==7){
			path(x-power[z],y+power[z],z+1,2);
			path(x-power[z],y+power[z],z+1,3);
		}
		if(q==8){
			path(x-power[z],y-power[z],z+1,3);
			path(x-power[z],y-power[z],z+1,4);
		}
	}else {
		path(x-power[z]+1,y,z+1,7);
		path(x-power[z]+1,y,z+1,8);
	}
}
int main(){
	cin>>n;
	rep(i,n)cin>>power[i];
	path(250,250,1,3);
	rep(i,500){
		rep(j,500)if(petasan[i][j])cnt++;
	}
	//for(int i=220;i<=280;i++){
	//	for(int j=220;j<=280;j++)cout<<petasan[i][j];
	//	cout<<endl;
	//}
	cout<<cnt<<endl;
	return 0;
}