#include <cstdio>
#include <cstring>
const int Maxn=200;
const int Maxm=300;
const int Mod=10007;
int len;
char s[Maxn+5];
int n,m;
int f[Maxn+5][Maxn+5][Maxn+5];
int g[Maxn+5];
struct Matrix{
	int a[Maxm+5][Maxm+5];
	int* operator [](int x){
		return a[x];
	}
	Matrix(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<=m;i++){
			for(int j=i;j<=m;j++){
				for(int k=i;k<=j;k++){
					ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%Mod;
				}
			}
		}
		return ans;
	}
}S,T;
Matrix a;
void ksm(){
	int b=(len+n+1)>>1;
	a=S;
	while(b){
		if(b&1){
			a=a*T;
		}
		b>>=1;
		T=T*T;
	}
}
int main(){
	scanf("%s",s+1);
	while(s[++len]!='\0');
	len--;
	scanf("%d",&n);
	f[1][len][0]=1;
	for(int i=1;i<=len;i++){
		for(int j=len;j>=i;j--){
			if(s[i]==s[j]){
				for(int k=0;k<i+len-j;k++){
					if(i+1<j){
						f[i+1][j-1][k]=(f[i+1][j-1][k]+f[i][j][k])%Mod;
					}
					else{
						g[k]=(g[k]+f[i][j][k])%Mod;
					}
				}
			}
			else{
				for(int k=0;k<i+len-j;k++){
					f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k])%Mod;
					f[i][j-1][k+1]=(f[i][j-1][k+1]+f[i][j][k])%Mod;
				}
			}
		}
	}
	m=(len+((len+1)>>1)+1);
	S[0][1]=1;
	S[0][m-((len+1)>>1)]=g[0];
	T[m][m]=26;
	for(int i=1;i<=len;i++){
		T[i][i]=24;
		T[i][m-((len-i+1)>>1)]=g[i];
		if(i!=len){
			T[i][i+1]=1;
		}
	}
	for(int i=len+1;i<m;i++){
		T[i][i+1]=1;
		T[i][i]=25;
	}
	if((len+n)&1){
		ksm();
		int ans=a[0][m];
		memset(S.a,0,sizeof S.a);
		memset(T.a,0,sizeof T.a);
		memset(g,0,sizeof g);
		for(int i=1;i<len;i++){
			if(s[i]==s[i+1]){
				for(int k=0;k<=len;k++){
					g[k]=(g[k]+f[i][i+1][k])%Mod;
				}
			}
		}
		S[0][1]=1;
		S[0][m-((len+1)>>1)]=g[0];
		for(int i=1;i<=len;i++){
			T[i][i]=24;
			T[i][m-((len-i+1)>>1)]=g[i];
			if(i!=len){
				T[i][i+1]=1;
			}
		}
		for(int i=len+1;i<m;i++){
			T[i][i+1]=1;
			T[i][i]=25;
		}
		ksm();
		ans=(ans-a[0][m]+Mod)%Mod;
		printf("%d\n",ans);
	}
	else{
		ksm();
		printf("%d\n",a[0][m]);
	}
	return 0;
}