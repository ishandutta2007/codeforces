#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	long long n,k,m,x;
	cin >> n >> k >> m;
	k=n-k;
	long long o=min(n/2,k);
	k-=o;
	long long oo=min(o,k);
	k-=oo;
	while (k--){
		if (o<=oo)o++;else oo++;
	}
	for (int i=0;i<m;i++){
		cin >> x;
		x--;
		if (x%2==0&&x/2<o||x%2&&x/2<oo)putchar('.');else putchar('X');
	}
	puts("");
	return 0;
}