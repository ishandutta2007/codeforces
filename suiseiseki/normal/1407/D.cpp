#include <cstdio>
#include <cstring>
void read(int& a){
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
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=300000;
int n;
int h[Maxn+5];
int f[Maxn+5];
int st[Maxn+5],top;
int big[Maxn+5],small[Maxn+5];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(h[i]);
	}
	for(int i=1;i<=n;i++){
		while(top&&h[st[top]]<=h[i]){
			top--;
		}
		big[i]=st[top];
		st[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++){
		while(top&&h[st[top]]>=h[i]){
			top--;
		}
		small[i]=st[top];
		st[++top]=i;
	}
	memset(f,0x3f,sizeof f);
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+1;
		if(h[i-1]<h[i]){
			int id=big[i-1];
			while(id){
				f[i]=min(f[i],f[id]+1);
				if(h[id]>=h[i]){
					break;
				}
				id=big[id];
			}
		}
		else if(h[i-1]>h[i]){
			int id=small[i-1];
			while(id){
				f[i]=min(f[i],f[id]+1);
				if(h[id]<=h[i]){
					break;
				}
				id=small[id];
			}
		}
	}
	printf("%d\n",f[n]);
	return 0;
}