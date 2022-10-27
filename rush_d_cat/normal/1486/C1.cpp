#include <bits/stdc++.h>
using namespace std;
int n;
int q(int l,int r){
	printf("? %d %d\n", l,r);
	fflush(stdout);
	int pos; scanf("%d",&pos); return pos;
}
int main() {
	scanf("%d",&n);
	int p=q(1,n);

	int l,r;
	if(p>1 && q(1,p)==p) {
		l=1,r=p;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(q(mid,p)==p) l=mid; else r=mid;
		}
		printf("! %d\n", l); fflush(stdout);
	}else{
		l=p,r=n;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(q(p,mid)==p) r=mid; else l=mid;
		}
		printf("! %d\n", r); fflush(stdout);
	}

}