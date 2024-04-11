#include<bits/stdc++.h>
using namespace std;
#define N 210
char a[N],b[N];
char sa[N],sb[N];
int main(){
	int Case;
	scanf("%d",&Case);
	while (Case--){
		scanf("%s%s",a+1,b+1);
		int n=strlen(a+1),m=strlen(b+1);
		int i;
		int ha=0,hb=0;
		int cnta=0,cntb=0;
		for (i=1;i<=n;i++){
			if (a[i]=='B'){
				cnta^=1;
			}else{
				if (ha>0 && sa[ha]==a[i]){
					ha--;
				}else{
					sa[++ha]=a[i];
				}
			}
		}
		for (i=1;i<=m;i++){
			if (b[i]=='B'){
				cntb^=1;
			}else{
				if (hb>0 && sb[hb]==b[i]){
					hb--;
				}else{
					sb[++hb]=b[i];
				}
			}
		}
		if (cnta==cntb && ha==hb && (ha==0 || sa[1]==sb[1])){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}