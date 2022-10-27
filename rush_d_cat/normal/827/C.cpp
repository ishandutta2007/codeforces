#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;

char s[N]; int n;
int pre[11][11][4][N];

int id(char c) {
	if(c=='A')return 0;
	if(c=='T')return 1;
	if(c=='G')return 2;
	return 3;
}

void upd(int m1,int m2,int id,int pos,int val){
	while(pos<N){
		pre[m1][m2][id][pos] += val;
		pos+=pos&-pos;
	}
}
int query(int m1,int m2,int id,int pos){
	int ans=0;
	while(pos>0){
		ans+=pre[m1][m2][id][pos];
		pos-=pos&-pos;
	}
	return ans;
}

int main() {
	scanf("%s", s + 1);
	n=strlen(s+1);
	for(int i=1;i<=10;i++){
		for(int j=1;j<=n;j++){
			upd(i,j%i,id(s[j]),j,1);
		}
	}
	int q; scanf("%d", &q);
	while(q--){

		int op;
		scanf("%d",&op);
		if(op==1){
			int x;char c[2]; scanf("%d%s",&x,c);
			for(int i=1;i<=10;i++) {
				upd(i,x%i,id(s[x]),x,-1);
			}
			s[x]=c[0];
			for (int i = 1; i <= 10; i ++) {
				upd(i,x%i,id(s[x]),x,+1);
			}
		} else {
			int l,r; char str[12]; 
			scanf("%d%d%s",&l,&r,str+1);
			int len=strlen(str+1),ans=0;
			for(int i=1;i<=len;i++){
				int m2=(l+i-1)%len;
				ans+=query(len,m2,id(str[i]),r) - query(len,m2,id(str[i]),l-1);
				// printf("# %d %d\n", query(len,m2,id(str[i]),r) , query(len,m2,id(str[i]),l-1));
			}
			printf("%d\n", ans);
		}
	}
}