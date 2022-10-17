#include <cstdio>
#include <cstring>
#define Maxn 2000
#define Inf 0x3f3f3f3f
int a[Maxn+5],b[Maxn+5];
int n;
int f[10][10][10][10][10];
int d[10][10][10][10][10];
int ab(int a){
	return a<0?-a:a;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	memset(f,0x3f,sizeof f);
	f[1][0][0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=4;k++){
			for(int j=1;j<=9;j++){
				for(int l1=0;l1<=9;l1++){
					for(int l2=0;l2<=9;l2++){
						for(int l3=0;l3<=9;l3++){
							for(int l4=0;l4<=9;l4++){
								if(f[j][l1][l2][l3][l4]<Inf){
									if(l1){
										f[l1][0][l2][l3][l4]=mn(f[l1][0][l2][l3][l4],f[j][l1][l2][l3][l4]+ab(j-l1)+1);
									}
									if(l2){
										f[l2][l1][0][l3][l4]=mn(f[l2][l1][0][l3][l4],f[j][l1][l2][l3][l4]+ab(j-l2)+1);
									}
									if(l3){
										f[l3][l1][l2][0][l4]=mn(f[l3][l1][l2][0][l4],f[j][l1][l2][l3][l4]+ab(j-l3)+1);
									}
									if(l4){
										f[l4][l1][l2][l3][0]=mn(f[l4][l1][l2][l3][0],f[j][l1][l2][l3][l4]+ab(j-l4)+1);
									}
								}
							}
						}
					}
				}
			}
		}
		memset(d,0x3f,sizeof d);
		for(int j=1;j<=9;j++){
			for(int l1=0;l1<=9;l1++){
				for(int l2=0;l2<=9;l2++){
					for(int l3=0;l3<=9;l3++){
						for(int l4=0;l4<=9;l4++){
							if(!l1){
								d[a[i]][b[i]][l2][l3][l4]=mn(d[a[i]][b[i]][l2][l3][l4],f[j][l1][l2][l3][l4]+ab(j-a[i])+1);
							}
							if(!l2){
								d[a[i]][l1][b[i]][l3][l4]=mn(d[a[i]][l1][b[i]][l3][l4],f[j][l1][l2][l3][l4]+ab(j-a[i])+1);
							}
							if(!l3){
								d[a[i]][l1][l2][b[i]][l4]=mn(d[a[i]][l1][l2][b[i]][l4],f[j][l1][l2][l3][l4]+ab(j-a[i])+1);
							}
							if(!l4){
								d[a[i]][l1][l2][l3][b[i]]=mn(d[a[i]][l1][l2][l3][b[i]],f[j][l1][l2][l3][l4]+ab(j-a[i])+1);
							}
						}
					}
				}
			}
		}
		for(int j=1;j<=9;j++){
			for(int l1=0;l1<=9;l1++){
				for(int l2=0;l2<=9;l2++){
					for(int l3=0;l3<=9;l3++){
						for(int l4=0;l4<=9;l4++){
							f[j][l1][l2][l3][l4]=d[j][l1][l2][l3][l4];
						}
					}
				}
			}
		}
	}
	for(int k=1;k<=4;k++){
		for(int j=1;j<=9;j++){
			for(int l1=0;l1<=9;l1++){
				for(int l2=0;l2<=9;l2++){
					for(int l3=0;l3<=9;l3++){
						for(int l4=0;l4<=9;l4++){
							if(f[j][l1][l2][l3][l4]<Inf){
								if(l1){
									f[l1][0][l2][l3][l4]=mn(f[l1][0][l2][l3][l4],f[j][l1][l2][l3][l4]+ab(j-l1)+1);
								}
								if(l2){
									f[l2][l1][0][l3][l4]=mn(f[l2][l1][0][l3][l4],f[j][l1][l2][l3][l4]+ab(j-l2)+1);
								}
								if(l3){
									f[l3][l1][l2][0][l4]=mn(f[l3][l1][l2][0][l4],f[j][l1][l2][l3][l4]+ab(j-l3)+1);
								}
								if(l4){
									f[l4][l1][l2][l3][0]=mn(f[l4][l1][l2][l3][0],f[j][l1][l2][l3][l4]+ab(j-l4)+1);
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=Inf;
	for(int j=1;j<=9;j++){
		ans=mn(ans,f[j][0][0][0][0]);
	}
	printf("%d\n",ans);
	return 0;
}