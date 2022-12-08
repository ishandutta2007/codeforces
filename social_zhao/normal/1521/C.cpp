#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;

int n;
inline int query(int t,int i,int j,int x){
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);scanf("%d",&x);
	return x;
}

int stk[MAXN],top;
inline void finish(int pos){
//	printf("!");
	int i;top=0;
	for(i=1;i<pos;++i) stk[++top]=query(1,pos,i,n-1);
	stk[++top]=1;
	for(i=pos+1;i<=n;++i) stk[++top]=query(1,pos,i,n-1);
	printf("!");
	for(i=1;i<=top;++i) printf(" %d",stk[i]);puts("");
	fflush(stdout);
}

inline void solve(int n){
	int i;
	int tmp=0,p1=0,p2=0;
	for(i=1;i+i<=n;++i){
		int x=query(2,2*i-1,i+i,1);
		if(x==2){
			if(!p1) p1=i;
			else p2=i;
		}
		else if(x==1){
			tmp=i+i-1;
			break;
		}
	}
	if(tmp) return finish(tmp);
	if(!p2){
		if(n&1){
			int x=query(2,p1*2,n,1);
			if(x==1) return finish(p1*2);
			return finish(n);
		}else return finish(p1*2);
	}
	int x=query(2,p1*2,p2*2,1);
	if(x==2) finish(p2*2);
	else finish(p1*2);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}