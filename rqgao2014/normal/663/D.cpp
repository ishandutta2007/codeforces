#include<bits/stdc++.h>
using namespace std;

int a[5005][3],n,tot,h[3],p[3],pst[3],ans,dp[2][91][91][91];
int score[6]={500,1000,1500,2000,2500,3000},xx[6],yy[6],maxx;

inline int calc(int s,int t){
	if(!t) return 0;
	return s*(250-t)/250;
}

inline void solve(int f,int s,int t){
	int k=0,score=(p[0]+p[1]+p[2])*100+calc(f,a[1][0])+calc(s,a[1][1])+calc(t,a[1][2]),res=0;
	memset(dp,0,sizeof(dp));
	for(int i=2;i<=n;i++){
		bool isok=1;
		int fs=calc(f,fabs(a[i][0])),ss=calc(s,fabs(a[i][1])),ts=calc(t,fabs(a[i][2])),sc=fs+ss+ts;
		for(int j=0;j<3;j++)
			if(a[i][j]<0) isok=0;
		if(isok){
			if(sc<=score) res++;
			continue;
		}
		k^=1;
		for(int h0=0;h0<=p[0];h0++)
			for(int h1=0;h1<=p[1];h1++)
				for(int h2=0;h2<=p[2];h2++){
					dp[k][h0][h1][h2]=0;
					for(int p0=0;p0<2&&p0<=h0;p0++){
						if(a[i][0]>=0&&p0) break;
						for(int p1=0;p1<2&&p1<=h1;p1++){
							if(a[i][1]>=0&&p1) break;
							for(int p2=0;p2<2&&p2<=h2;p2++){
								if(a[i][2]>=0&&p2) break;
								int now=sc-fs*p0-ss*p1-ts*p2;
								if(now<=score) now=1; else now=0;
								dp[k][h0][h1][h2]=max(dp[k][h0][h1][h2],dp[k^1][h0-p0][h1-p1][h2-p2]+now);
							}
						}
					}
				}
	}
	ans=min(ans,n-res-dp[k][p[0]][p[1]][p[2]]);
}


int main(){
	scanf("%d",&n);ans=n;
	xx[0]=n/2,yy[0]=n;
	for(int i=1;i<6;i++) xx[i]=xx[i-1]/2,yy[i]=yy[i-1]/2;
	for(int i=0;i<5;i++) xx[i]++;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			tmp+=calc(3000,a[i][j]);
			if(a[i][j]<0) tot++,h[j]++;
			if(a[i][j]!=0) pst[j]++;
		}
		maxx=max(maxx,tmp);
	}
	if(tot*100>=maxx){puts("1");return 0;}
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			for(int k=0;k<6;k++){
				if(xx[i]>yy[i]||xx[j]>yy[j]||xx[k]>yy[k]) continue;
				bool isok=1;
				p[0]=pst[0]-yy[i];
				p[1]=pst[1]-yy[j];
				p[2]=pst[2]-yy[k];
				for(int t=0;t<3;t++) if(p[t]>h[t]) isok=0;
				p[0]=min(pst[0]-xx[i],h[0]);
				p[1]=min(pst[1]-xx[j],h[1]);
				p[2]=min(pst[2]-xx[k],h[2]);
				for(int t=0;t<3;t++) if(p[t]<0) isok=0;
				if(!isok) continue;
				solve(score[i],score[j],score[k]);
			}
	printf("%d\n",ans);
	return 0;
}