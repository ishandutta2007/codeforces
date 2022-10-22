#include<bits/stdc++.h>
using namespace std;
#define Step 40000
const int fx[8]={1,1,-1,-1,2,2,-2,-2},fy[8]={2,-2,2,-2,1,-1,1,-1};
struct data{
	int op,x,y,k,lon;
	data(int O=0,int X=0,int Y=0,int K=0,int L=0){op=O;x=X;y=Y;k=K;lon=L;}
	bool friend operator<(data a,data b){
		return a.lon>b.lon;
	}
}step[105];
priority_queue<data>Q;
int f[3][11][11][105],vis[3][11][11][105],n,a;
void chk(int op1,int a,int b,int op2,int c,int d,int k1){
//	cout<<"HI "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	//cout<<"chk: "<<op1<<" "<<a<<" "<<b<<" "<<op2<<" "<<c<<" "<<d<<" "<<k1<<endl;
	int k2=k1;
	if(c==step[k1+1].x&&d==step[k1+1].y)k2++;
	if(f[op2][c][d][k2]>f[op1][a][b][k1]+(op1==op2?(Step):(Step+1))){
		f[op2][c][d][k2]=f[op1][a][b][k1]+(op1==op2?(Step):(Step+1));
		Q.push(data(op2,c,d,k2,f[op2][c][d][k2]));
	}
}
void Dijstra(){
	memset(f,0x3f,sizeof(f));
	int x=step[1].x,y=step[1].y;
	f[0][x][y][1]=f[1][x][y][1]=f[2][x][y][1]=0;
	Q.push(data(0,x,y,1,0));
	Q.push(data(1,x,y,1,0));
	Q.push(data(2,x,y,1,0));
	while(!Q.empty()){
		data w=Q.top();
		Q.pop();
		int op=w.op,x=w.x,y=w.y,k=w.k;
		if(vis[op][x][y][k])continue;
		vis[op][x][y][k]=1;
		chk(op,x,y,0,x,y,k);
		chk(op,x,y,1,x,y,k);
		chk(op,x,y,2,x,y,k);
		if(!op)
			for(int i=1;i<=n;++i)
				chk(op,x,y,op,i,y,k),chk(op,x,y,op,x,i,k);
		if(op==1)
			for(int i=0;i<8;++i)
				if(x+fx[i]>0&&x+fx[i]<=n&&y+fy[i]>0&&y+fy[i]<=n)
					chk(op,x,y,op,x+fx[i],y+fy[i],k);
		if(op==2){
			for(int i=1;max(x,y)+i<=n;++i)
				chk(op,x,y,op,x+i,y+i,k);
			for(int i=1;min(x,y)-i>0;++i)
				chk(op,x,y,op,x-i,y-i,k);
			for(int i=1;y+i<=n&&x-i>0;++i)
				chk(op,x,y,op,x-i,y+i,k);
			for(int i=1;y-i>0&&x+i<=n;++i)
				chk(op,x,y,op,x+i,y-i,k);
		}
	//	puts("END");
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			scanf("%d",&a);
			step[a].x=i;
			step[a].y=j;
		}
	Dijstra();
	int x=step[n*n].x,y=step[n*n].y;
	int res=min(f[0][x][y][n*n],min(f[1][x][y][n*n],f[2][x][y][n*n]));
	printf("%d %d",res/Step,res%Step);
	return 0;
}