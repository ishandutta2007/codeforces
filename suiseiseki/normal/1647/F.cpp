#include <map>
#include <cstdio>
#include <algorithm>
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int f[Maxn+5][2],g[Maxn+5][2];
std::map<int,bool> mp;
int pos;
bool flag[Maxn+5];
void init_f(){
	f[0][0]=f[0][1]=1;
	for(int i=1;i<=n;i++){
		if(i<pos){
			int tmp=Inf;
			if(a[i]>a[i-1]){
				tmp=f[i-1][0];
			}
			if(a[i]>f[i-1][0]){
				tmp=std::min(tmp,a[i-1]);
			}
			f[i][0]=f[i][1]=tmp;
		}
		else if(i==pos){
			int tmp=Inf;
			if(a[i]>a[i-1]){
				tmp=f[i-1][0];
			}
			if(a[i]>f[i-1][0]){
				tmp=std::min(tmp,a[i-1]);
			}
			f[i][0]=tmp,f[i][1]=0;
		}
		else{
			int tmp=Inf;
			if(a[i]<a[i-1]){
				tmp=f[i-1][0];
			}
			if(a[i]<f[i-1][1]){
				tmp=std::min(tmp,a[i-1]);
			}
			f[i][0]=tmp;
			tmp=0;
			if(a[i]>a[i-1]){
				tmp=f[i-1][1];
			}
			if(a[i]>f[i-1][0]){
				tmp=std::max(tmp,a[i-1]);
			}
			f[i][1]=tmp;
		}
	}
}
void init_g(){
	g[n+1][0]=g[n+1][1]=0;
	for(int i=n;i>0;i--){
		if(i>pos){
			int tmp=Inf;
			if(a[i]>a[i+1]){
				tmp=g[i+1][0];
			}
			if(a[i]>g[i+1][0]){
				tmp=std::min(tmp,a[i+1]);
			}
			g[i][0]=g[i][1]=tmp;
		}
		else if(i==pos){
			int tmp=Inf;
			if(a[i]>a[i+1]){
				tmp=g[i+1][0];
			}
			if(a[i]>g[i+1][0]){
				tmp=std::min(tmp,a[i+1]);
			}
			g[i][0]=tmp,g[i][1]=0;
		}
		else{
			int tmp=Inf;
			if(a[i]<a[i+1]){
				tmp=g[i+1][0];
			}
			if(a[i]<g[i+1][1]){
				tmp=std::min(tmp,a[i+1]);
			}
			g[i][0]=tmp;
			tmp=0;
			if(a[i]>a[i+1]){
				tmp=g[i+1][1];
			}
			if(a[i]>g[i+1][0]){
				tmp=std::max(tmp,a[i+1]);
			}
			g[i][1]=tmp;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[pos]<a[i]){
			pos=i;
		}
	}
	init_f();
	init_g();
	for(int i=1;i<=n;i++){
		if(i!=pos){
			if(i<pos){
				int tmp=f[i][1];
				if(tmp<a[i+1]&&a[i]>g[i+1][0]){
					mp[a[i]]=1;
				}
				if(tmp<g[i+1][1]&&a[i]>a[i+1]){
					mp[a[i]]=1;
				}
			}
			else{
				int tmp=g[i][1];
				if(tmp<a[i-1]&&a[i]>f[i-1][0]){
					mp[a[i]]=1;
				}
				if(tmp<f[i-1][1]&&a[i]>a[i-1]){
					mp[a[i]]=1;
				}
			}
		}
	}
	printf("%d\n",(int)mp.size());
	return 0;
}