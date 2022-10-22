#include<bits/stdc++.h>
using namespace std;
#define MN 5005
int n,s[2][2],q[2][2][2],num[2][2][MN];
char x[MN],y[MN];
bool chk1(){
	return q[0][1][0]+q[0][1][1]<q[1][0][1]+q[1][1][1];
}
bool chk2(){
	return q[0][1][0]+q[0][1][1]>q[1][0][1]+q[1][1][1];
}
void change(int x1,int y1,int x2,int y2){
	q[0][x1][y1]--;q[1][x1][y1]++;
	q[0][x2][y2]++;q[1][x2][y2]--;
}
int main(){
	int Be=clock();
	scanf("%d",&n);
	scanf("%s",x+1);
	scanf("%s",y+1);
	for(int i=1;i<=n;++i){
		x[i]-='0';y[i]-='0';
		s[x[i]][y[i]]++;
		q[i>(n>>1)][x[i]][y[i]]++;
		num[x[i]][y[i]][s[x[i]][y[i]]]=i;
	}
	int CNT=0;
	memset(s,0,sizeof(s));
	while(chk1()||chk2()){
		CNT++;
		if(CNT>(n>>1)+1) break;
		if(chk1()){
			bool t=0;
			if(q[1][1][1]){
				if(q[0][0][1]){
					t=1;
					change(0,1,1,1);
				}
				else if(q[0][1][0]){
					t=1;
					change(1,0,1,1);
				}
			}
			if(!t&&q[0][0][0]){
				if(q[1][1][0]){
					t=1;
					change(0,0,1,0);
				}
				else if(q[1][0][1]){
					t=1;
					change(0,0,0,1);
				}
				else if(q[1][1][1]){
					t=1;
					change(0,0,1,1);
				}
			}
			if(!t){puts("-1");return 0;}
		}
		if(chk2()){
			bool t=0;
			if(q[0][1][1]){
				if(q[1][1][0]){
					t=1;
					change(1,1,1,0);
				}
				else if(q[1][0][1]){
					t=1;
					change(1,1,0,1);
				}
			}
			if(!t&&q[1][0][0]){
				if(q[0][0][1]){
					t=1;
					change(0,1,0,0);
				}
				else if(q[0][1][0]){
					t=1;change(1,0,0,0);
				}
				else if(q[0][1][1]){
					t=1;
					change(1,1,0,0);
				}
			}
			if(!t){puts("-1");return 0;}
		}
	}
	if(chk1()||chk2()){puts("-1");return 0;}
	for(int j=0;j<2;++j)
		for(int k=0;k<2;++k)
			for(int l=0;l<q[0][j][k];++l){
				printf("%d ",num[j][k][++s[j][k]]);
			}
	return 0;
}