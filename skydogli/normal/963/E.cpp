#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define mn 55
#define MN 7849
#define Mod 1000000007
const int fx[4]={-1,0,1,0},fy[4]={0,-1,0,1};
LL ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}

int a[4],R,cnt,D;
int f[MN][MN],g[MN];
int id[mn*2][mn*2];
bool chk(int x,int y){
	return x*x+y*y<=R*R;
}
void Gauss(){
	for(int i=1;i<=cnt;++i){
		int k=ksm(f[i][i],Mod-2);
		for(int j=i;j<=cnt&&j<=i+D;++j){
			f[i][j]=1ll*f[i][j]*k%Mod;
		}
		f[i][cnt+1]=1ll*f[i][cnt+1]*k%Mod;
		for(int j=i+1;j<=cnt&&j<=i+D;++j){
			int tmp=f[j][i];
			if(!tmp)continue;
			for(int k=i;k<=cnt&&k<=i+D;++k){
				f[j][k]=(1ll*f[j][k]-1ll*tmp*f[i][k]%Mod+Mod)%Mod;
			}
			f[j][cnt+1]=(1ll*f[j][cnt+1]-1ll*tmp*f[i][cnt+1]%Mod+Mod)%Mod;
		}
	}
}
void calc(){
	for(int i=cnt;i;--i){
		int val=f[i][cnt+1];
		for(int j=i+1;j<=cnt&&j<=i+D;++j){
			val=(1ll*val-1ll*g[j]*f[i][j]%Mod+Mod)%Mod;
		}
		g[i]=val;
//		cerr<<"g "<<i<<": "<<g[i]<<endl;
	}
}
int main(){
	scanf("%d%d%d%d%d",&R,&a[0],&a[1],&a[2],&a[3]);
	int s=a[0]+a[1]+a[2]+a[3];
	for(int i=0;i<4;++i)a[i]=1ll*a[i]*ksm(s,Mod-2)%Mod;
	for(int x=-R;x<=R;++x)
		for(int y=-R;y<=R;++y){
			if(chk(x,y)){
				id[x+R][y+R]=++cnt;					
			}
		}
	for(int x=-R;x<=R;++x)
		for(int y=-R;y<=R;++y){
			if(chk(x,y)){
				int p=id[x+R][y+R];
				f[p][p]=1;f[p][cnt+1]=1;
				for(int i=0;i<4;++i){
					int X=x+fx[i],Y=y+fy[i];
					if(chk(X,Y)){
						f[p][id[X+R][Y+R]]=Mod-a[i];
//						cerr<<"EDG: "<<x<<" "<<y<<" , "<<X<<" "<<Y<<endl;
					}
				//	else (f[p][cnt+1]+=Mod-a[i])%=Mod;
				}
//				cerr<<"? "<<p<<" "<<f[p][cnt+1]<<endl;
			}
		}
	D=R*2+1;
	Gauss();
	calc();
	printf("%d\n",g[id[R][R]]);
	return 0;
}