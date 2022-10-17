#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
const int Maxn=100000;
const int Maxk=1000;
const int Inf=0x7f7f7f7f;
int n,m;
int a[Maxn+5],b[Maxn+5];
bool vis[Maxn+5];
int f[Maxn+5];
int g[Maxn+5];
int p[Maxn+5],pos[Maxn+5];
int ans[Maxn+5];
void get(int i,int k,int &x){
	int tmp=lower_bound(b+1,b+1+m,k)-b-1;
	vis[tmp]=1;
	x=ans[i]=b[tmp];
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		f[i]=Inf;
	}
	n++;
	a[n]=Inf;
	f[n]=Inf;
	read(m);
	for(int i=1;i<=m;i++){
		read(b[i]);
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			for(int j=n,k=m;k>0;k--){
				while(f[j]>=b[k]){
					j--;
				}
				f[j+1]=b[k];
				pos[j+1]=i;
			}
		}
		else{
			int j=lower_bound(f+1,f+1+n,a[i])-f-1;
			g[i]=j+1;
			p[i]=pos[j];
			f[j+1]=a[i];
			pos[j+1]=i;
		}
	}
	{
		int i=g[n],j=n,x=a[n];
		while(i--){
			if(a[j]!=-1){
				if(a[p[j]]==-1){
					get(p[j],a[j],x);
				}
				else{
					x=a[p[j]];
				}
				j=p[j];
			}
			else{
				bool flag=0;
				for(int s=j-1;s>0;s--){
					if(a[s]!=-1&&g[s]==i&&a[s]<x){
						x=a[j=s];
						flag=1;
						break;
					}
				}
				if(flag){
					continue;
				}
				for(int s=j-1;s>0;s--){
					if(a[s]==-1){
						get(s,x,x);
						j=s;
						break;
					}
				}
			}
		}
	}
	for(int i=1,j=1;i<n;i++){
		if(a[i]==-1){
			if(ans[i]!=0){
				a[i]=ans[i];
				continue;
			}
			while(vis[j]){
				j++;
			}
			vis[j]=1;
			a[i]=b[j];
		}
	}
	for(int i=1;i<n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}