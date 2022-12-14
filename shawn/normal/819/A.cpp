#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int v[110],A[2010],ans=10010,f[20],a,b,l,r,L,R;

inline bool Apr(int l,int r,int x){
	for (int i=max(1,l);i<=r;i++) if(A[i]==x) return(1);
	return(0);
}
inline void Work(){
	int lst=0;
	for (int i=1;i<=4;i++){
		
		if (!f[i*2-1]){
			for (int k=0,j=1;j<=a;j++){
				while (Apr(lst-a+1,lst,k)) k++;
				A[lst+j]=k,k++;
			}
		}else{
			for (int k=0,j=a;j>=1;j--){
				while (Apr(lst-a+1,lst,k)) k++;
				A[lst+j]=k,k++;
			}
		}
		if (!f[i*2]){
			int mn=100;
			for (int j=1;j<=a;j++) mn=min(mn,A[lst+j]);
			for (int j=1;j<=b;j++) A[lst+a+j]=mn;
		}else{
			int mx=0;
			for (int j=1;j<=a;j++) mx=max(mx,A[lst+j]);
			for (int j=1;j<=b;j++) A[lst+a+j]=mx;
		}
		
		lst+=a+b;
	}
	
	int nm=0;
	memset(v,0,sizeof(v));
	for (int i=l;i<=r;i++) v[A[i]]=1;
	for (int i=0;i<=100;i++) nm+=v[i];
	ans=min(ans,nm);
}

inline void Dfs(int x){
	if (x>10) {Work();return;}
	
	f[x]=0;
	Dfs(x+1);
	f[x]=1;
	Dfs(x+1);
	f[x]=0;
}

int main()
{
//	freopen("1.in","r",stdin);
	
	scanf("%d%d%d%d",&a,&b,&L,&R);
	
	l=L%(a+b);if(!l)l=a+b;
	r=l+(R-L);if(r>(a+b)*4)r-=(r/(a+b)-4)*(a+b);
	
	
	Dfs(2);
	
	printf("%d\n",ans);
}