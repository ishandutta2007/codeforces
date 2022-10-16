#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Maxm=500;
const int Maxb=400;
int n,m;
int a[Maxn+5],b[Maxn+5];
int s[Maxn+5];
int c[Maxm+5][Maxm+5];
int t[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=1,now=0,tot=0;i<=m;i++){
		int op,k;
		scanf("%d%d",&op,&k);
		tot+=(op==1?1:-1);
		int w=t[k]?-1:1;
		int pos=t[k]?t[k]:i;
		t[k]=t[k]?0:i;
		int len=a[k]+b[k];
		if(len<=Maxb){
			for(int j=pos%len,z=0;z<a[k];z++,j=(j+1)%len){
				c[len][j]+=w;
			}
		}
		else{
			for(int j=pos;j<=m;j+=len){
				if(pos!=i&&i>j&&i<=j+a[k]){
					now--;
				}
				s[j]+=w;
				s[std::min(m+1,j+a[k])]-=w;
			}
		}
		now+=s[i];
		int ans=now;
		for(int j=2;j<=Maxb;j++){
			ans+=c[j][i%j];
		}
		printf("%d\n",tot-ans);
	}
	return 0;
}