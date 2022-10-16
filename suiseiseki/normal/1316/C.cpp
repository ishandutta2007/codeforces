#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=1000000;
int n,m,p;
int a[Maxn+5],b[Maxn+5];
int main(){
	read(n),read(m),read(p);
	n--,m--;
	for(int i=0;i<=n;i++){
		read(a[i]);
		a[i]%=p;
	}
	for(int i=0;i<=m;i++){
		read(b[i]);
		b[i]%=p;
	}
	while(a[n]==0){
		n--;
	}
	while(b[m]==0){
		m--;
	}
	printf("%d\n",n+m);
	return 0;
}