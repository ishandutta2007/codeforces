#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Maxn 200000
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
vector<int> a[Maxn+5];
int f[Maxn+5];
int pre[Maxn+5];
bool cant[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int now[Maxn+5];
int phi;
int n,m;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=(int)((long long)ans*a%m);
		}
		a=(int)((long long)a*a%m);
		b>>=1;
	}
	return ans;
}
int get(int a,int b){
	int g=gcd(a,b);
	a/=g,b/=g;
	return (int)((long long)b*ksm(a,phi-1)%m);
}
int main(){
	scanf("%d%d",&n,&m);
	phi=m;
	int _n=m;
	for(int i=2;i*i<=_n;i++){
		if(_n%i==0){
			phi/=i;
			phi*=i-1;
			while(_n%i==0){
				_n/=i;
			}
		}
	}
	if(_n>1){
		phi/=_n;
		phi*=_n-1;
	}
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		cant[x]=1;
	}
	for(int i=0;i<m;i++){
		if(!cant[i]){
			a[gcd(i,m)].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(m%i){
			continue;
		}
		f[i]+=a[i].size();
		for(int j=i+i;j<=m;j+=i){
			if(m%j){
				continue;
			}
			if(f[j]<f[i]){
				f[j]=f[i];
				pre[j]=i;
			}
		}
	}
	int tmp=m;
	int len=0;
	while(tmp!=0){
		for(int i=0;i<(int)a[tmp].size();i++){
			now[++len]=a[tmp][i];
		}
		tmp=pre[tmp];
	}
	printf("%d\n",len);
	printf("%d ",now[len]);
	for(int i=len;i>1;i--){
		printf("%d ",get(now[i],now[i-1]));
	}
	puts("");
	return 0;
}