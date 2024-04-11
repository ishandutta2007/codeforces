#include <bits/stdc++.h>
using namespace std;

int n,q;
char s[100005];
int A[255],B[255],C[255];
int la,lb,lc;
int dp[255][255][255];
int vcl[100005][30];

void upd(int na,int nb,int nc){
	if(!na&&!nb&&!nc){
		return;
	}
	dp[na][nb][nc]=n+1;
	if(na){
		dp[na][nb][nc]=min(dp[na][nb][nc],vcl[dp[na-1][nb][nc]+1][A[na]]);
	}
	if(nb){
		dp[na][nb][nc]=min(dp[na][nb][nc],vcl[dp[na][nb-1][nc]+1][B[nb]]);
	}
	if(nc){
		dp[na][nb][nc]=min(dp[na][nb][nc],vcl[dp[na][nb][nc-1]+1][C[nc]]);
	}
}

int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int j=0;j<26;j++){
		vcl[n+1][j]=vcl[n+2][j]=n+1;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++){
			vcl[i][j]=vcl[i+1][j];
		}
		vcl[i][s[i]-'a']=i;
	}
	while(q--){
		char mode;
		int whr;
		scanf(" %c%d",&mode,&whr);
		if(mode=='+'){
			char val;
			scanf(" %c",&val);
			if(whr==1){
				A[++la]=val-'a';
			}else if(whr==2){
				B[++lb]=val-'a';
			}else{
				C[++lc]=val-'a';
			}
		}else{
			if(whr==1){
				la--;
			}else if(whr==2){
				lb--;
			}else{
				lc--;
			}
		}
		if(whr==1){
			for(int i=0;i<=lb;i++){
				for(int j=0;j<=lc;j++){
					upd(la,i,j);
				}
			}
		}else if(whr==2){
			for(int i=0;i<=la;i++){
				for(int j=0;j<=lc;j++){
					upd(i,lb,j);
				}
			}
		}else{
			for(int i=0;i<=la;i++){
				for(int j=0;j<=lb;j++){
					upd(i,j,lc);
				}
			}
		}
		if(dp[la][lb][lc]==n+1){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}