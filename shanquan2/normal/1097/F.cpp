#include<bits/stdc++.h>
using namespace std;

int n,q;
bitset<7005> a[100005],b[7005],c[7005],v;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=7005;i++){
		v[i]=1;
		for(int j=2;j<=100;j++)if(i%(j*j)==0)v[i]=0;
	}
	for(int i=1;i<=7000;i++){
		for(int j=1;j<=7000;j++){
			if(i%j==0)b[i][j]=1;
			if(j%i==0){
				c[i][j]=v[j/i];
			}
		}
	}
	while(q--){
		int tp;scanf("%d",&tp);
		if(tp==1){
			int x,v;scanf("%d%d",&x,&v);
			a[x]=b[v];
		}else if(tp==2){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]^a[z];
		}else if(tp==3){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]&a[z];
		}else if(tp==4){
			int x,v;scanf("%d%d",&x,&v);
			printf("%d",(c[v]&a[x]).count()&1);
		}
	}
}