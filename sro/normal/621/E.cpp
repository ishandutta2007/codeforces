#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SZ(s) ((int)(s).size())
#define INT long long
#define Mod 1000000007
using namespace std;

int n,b,k,x;
INT mat[105][105],mat2[105][105];//x*x matrix
INT ozym[105][105];

void Ghvchn(int fau){
	if(!fau){
		for(int i=0;i<x;i++){
			for(int j=0;j<x;j++){
				mat[i][j]=(i==j);
			}
		}
		return;
	}
	Ghvchn(fau/2);
	memset((INT*)mat2,0,sizeof(mat2));
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			for(int k=0;k<x;k++){
				mat2[i][k]=(mat2[i][k]+mat[i][j]*mat[j][k])%Mod;
			}
		}
	}
	if(fau%2){
		memset((INT*)mat,0,sizeof(mat));
		for(int i=0;i<x;i++){
			for(int j=0;j<x;j++){
				for(int k=0;k<x;k++){
					mat[i][k]=(mat[i][k]+mat2[i][j]*ozym[j][k])%Mod;
				//cerr<<i<<' '<<j<<' '<<k<<' '<<mat2[i][j]<<' '<<ozym[j][k]<<' '<<mat[i][k]<<endl;
				}
			}
		}
	}else{
		for(int i=0;i<x;i++){
			for(int j=0;j<x;j++){
				mat[i][j]=mat2[i][j];
			}
		}
	}
}

int CNT[15];

int main(){
	scanf("%d%d%d%d",&n,&b,&k,&x);
	for(int i=0;i<n;i++){
		int ab;
		scanf("%d",&ab);
		CNT[ab]++;
	}
	for(int i=0;i<x;i++){
		for(int k=0;k<10;k++){
			ozym[i][(i*10+k)%x]=(ozym[i][(i*10+k)%x]+CNT[k])%Mod;
			//cerr<<i<<' '<<(i*10+k)%x<<' '<<CNT[k]<<endl;
		}
	}
	Ghvchn(b);
	#ifdef ORZDALAO
	printf("%lld\n",mat[0][k]);
	#else
	printf("%I64d\n",mat[0][k]);
	#endif
}