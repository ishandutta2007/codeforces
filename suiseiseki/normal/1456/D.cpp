#include <cstdio>
#include <cstring>
int abs(int a){
	return a<0?-a:a;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=5000;
int n;
int t[Maxn+5],x[Maxn+5];
int f_1[Maxn+5],f_2[Maxn+5];
bool g[Maxn+5][Maxn+5];
int min_dis(int left,int right,int x){
	if(x<left){
		return left-x;
	}
	if(x>right){
		return x-right;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t[i],&x[i]);
	}
	memset(f_1,-1,sizeof f_1);
	memset(f_2,-1,sizeof f_2);
	f_1[0]=0;
	for(int i=0;i<n;i++){
		int d=t[i+1]-t[i];
		if(abs(x[i+1]-x[i])<=d){
			for(int j=i+2;j<=n;j++){
				if(g[i][j]){
					g[i+1][j]=1;
				}
			}
		}
		if(g[i][i+1]){
			f_2[i+1]=max(f_2[i+1],d);
		}
		if(f_1[i]>=0){
			int left=x[i]-f_1[i],right=x[i]+f_1[i];
			if(x[i+1]<left-d){}
			else if(x[i+1]<left){
				f_1[i+1]=max(f_1[i+1],x[i+1]-(left-d));
			}
			else if(x[i+1]<right){
				f_1[i+1]=max(f_1[i+1],d);
			}
			else if(x[i+1]<=right+d){
				f_1[i+1]=max(f_1[i+1],(right+d)-x[i+1]);
			}
			else{}
			for(int j=i+2;j<=n;j++){
				int t_max=t[i+1]-abs(x[i+1]-x[j]);
				if(min_dis(left,right,x[j])<=t_max-t[i]){
					g[i+1][j]=1;
				}
			}
		}
		if(f_2[i]>=0){
			int left=x[i-1]-f_2[i],right=x[i-1]+f_2[i];
			if(x[i+1]<left-d){}
			else if(x[i+1]<left){
				f_1[i+1]=max(f_1[i+1],x[i+1]-(left-d));
			}
			else if(x[i+1]<right){
				f_1[i+1]=max(f_1[i+1],d);
			}
			else if(x[i+1]<=right+d){
				f_1[i+1]=max(f_1[i+1],(right+d)-x[i+1]);
			}
			else{}
			for(int j=i+2;j<=n;j++){
				int t_max=t[i+1]-abs(x[i+1]-x[j]);
				if(min_dis(left,right,x[j])<=t_max-t[i]){
					g[i+1][j]=1;
				}
			}
		}
	}
	if(g[n-1][n]||f_1[n]>=0||f_2[n]>=0){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}