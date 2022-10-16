#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=75;
const int Inf=0x3f3f3f3f;
int n;
char s[Maxn+5];
int f[Maxn+5][Maxn+5][Maxn+5][2];
int lis_1[Maxn+5],lis_2[Maxn+5],lis_3[Maxn+5];
int len_1,len_2,len_3;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='V'){
			lis_1[len_1++]=i;
		}
		else if(s[i]=='K'){
			lis_2[len_2++]=i;
		}
		else{
			lis_3[len_3++]=i;
		}
	}
	memset(f,0x3f,sizeof f);
	f[0][0][0][0]=0;
	for(int i=0;i<=len_1;i++){
		for(int j=0;j<=len_2;j++){
			for(int k=0;k<=len_3;k++){
				for(int t=0;t<2;t++){
					auto find_val=[&](int pos){
						int ans=0;
						for(int l=i;l<len_1&&lis_1[l]<pos;l++){
							ans++;
						}
						for(int l=j;l<len_2&&lis_2[l]<pos;l++){
							ans++;
						}
						for(int l=k;l<len_3&&lis_3[l]<pos;l++){
							ans++;
						}
						return ans;
					};
					if(i<len_1){
						f[i+1][j][k][1]=std::min(f[i+1][j][k][1],f[i][j][k][t]+find_val(lis_1[i]));
					}
					if(j<len_2&&t==0){
						f[i][j+1][k][0]=std::min(f[i][j+1][k][0],f[i][j][k][t]+find_val(lis_2[j]));
					}
					if(k<len_3){
						f[i][j][k+1][0]=std::min(f[i][j][k+1][0],f[i][j][k][t]+find_val(lis_3[k]));
					}
				}
			}
		}
	}
	int ans=Inf;
	for(int i=0;i<2;i++){
		ans=std::min(ans,f[len_1][len_2][len_3][i]);
	}
	printf("%d\n",ans);
	return 0;
}