#include <bits/stdc++.h>
using namespace std;

int w[8];
const int Mod=1000000007;

struct Matrix{
	int a[128][128];
	int lim;
	Matrix(){
		for(int i=0;i<128;i++){
			for(int j=0;j<128;j++){
				a[i][j]=0;
			}
		}
		lim=128;
	}
	Matrix(int x){
		for(int i=0;i<128;i++){
			for(int j=0;j<128;j++){
				if(i==j){
					a[i][j]=x;
				}else{
					a[i][j]=0;
				}
			}
		}
		lim=128;
	}
	Matrix operator*(const Matrix &mat)const{
		Matrix ans;
		ans.lim=lim;
		for(int i=0;i<lim;i++){
			for(int j=0;j<lim;j++){
				for(int k=0;k<lim;k++){
					ans.a[i][k]=(ans.a[i][k]+1ll*a[i][j]*mat.a[j][k])%Mod;
				}
			}
		}
		return ans;
	}
};

Matrix I=1;

Matrix ksmii(Matrix a,int b){
	if(!b){
		return I;
	}
	Matrix ans=ksmii(a,b>>1);
	ans=ans*ans;
	if(b&1){
		ans=ans*a;
	}
	return ans;
}

int main(){
	for(int i=1;i<=7;i++){
		scanf("%d",w+i);
	}
	Matrix zy=I;
	for(int i=1;i<=7;i++){
		Matrix tr;
		int ful=(1<<i)-1;
		for(int x=0;x<(1<<i);x++){
			for(int y=0;y<(1<<i);y++){
				for(int z=0;z<(1<<(i-1));z++){
					bool can=1;
					for(int k=0;k<i;k++){
						if(!((x>>k)&1)&&!((y>>k)&1)&&(k==0||!((z>>(k-1))&1))&&(k==i-1||!((z>>k)&1))){
							can=0;
							break;
						}
					}
					if(!can){
						continue;
					}
					tr.a[x][y]++;
				}
			}
		}
		I.lim=(1<<i);
		zy.lim=(1<<i);
		tr.lim=(1<<i);
		tr=ksmii(tr,w[i]);
		zy=zy*tr;
	}
	printf("%d\n",zy.a[0][0]);
}