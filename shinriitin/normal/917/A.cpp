#include <bits/stdc++.h>

const int max_N = 5000 + 21;

int n,ans;

bool ok1[max_N][max_N];

bool ok2[max_N][max_N];

char s[max_N];

int main(){
	scanf("%s",s);
	n = strlen(s);
	for(int i=0;i<n;++i){
		int l_bra=0,r_bra=0;
		for(int j=i;j<n;++j){
			if(s[j]!=')')++l_bra;
			else ++r_bra;
			if(l_bra<r_bra)break;
			ok1[i][j]=1;
		}
	}
	for(int i=n-1;~i;--i){
		int l_bra=0,r_bra=0;	
		for(int j=i;~j;--j){
			if(s[j]!='(')++r_bra;
			else ++l_bra;
			if(r_bra<l_bra)break;
			ok2[j][i]=1;
		}
	}
	for(int i=0;i<n;++i)
		for(int j=i;j<n;++j)
			if(((i+j)&1)&&ok1[i][j]&&ok2[i][j]){
				++ans;	
			}
	printf("%d\n",ans);
	return 0;
}