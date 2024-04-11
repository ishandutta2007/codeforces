#include<stdio.h>
#include<queue>
using namespace std;
#define N 1001

struct pnt{
	int h,w,z;
	pnt(int h,int w,int z):h(h),w(w),z(z){}
};

bool operator == (pnt a,pnt b){
	if(a.h==b.h&&a.w==b.w)return 1;
	return 0;
}

int r,c;
int p[N][N];
int chk[N][N];
int dh[]={-1,0,1,0},dw[]={0,1,0,-1};

int main(){
	//freopen("2.in","r",stdin);
	int i,j,k;
	char C;
	scanf("%d%d\n",&r,&c);
	queue<pnt>q;
	for(i=1;i<=r;i++)for(j=1;j<=c;j++){
		scanf("%c\n",&C);
		if(C=='S')p[i][j]=-N;
		else if(C=='E')p[i][j]=N,q.push(pnt(i,j,0)),chk[i][j]=1;
		else if(C=='T')p[i][j]=-1;
		else p[i][j]=C-'0';
	}

	int ans=0,dep=N*N;
	while(!q.empty()){
		pnt en=q.front();q.pop();
		if(en.z<=dep)ans+=p[en.h][en.w];
		for(k=0;k<4;k++){
			i=en.h+dh[k];j=en.w+dw[k];
			if(i<1||i>r||j<1||j>c||p[i][j]==-1||chk[i][j])continue;
			if(p[i][j]==-N)dep=en.z+1;
			q.push(pnt(i,j,en.z+1));
			chk[i][j]=1;
		}
	}
	printf("%d\n",ans);
}