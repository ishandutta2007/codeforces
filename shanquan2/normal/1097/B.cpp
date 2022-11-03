#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	bool f=1;
	for(int i=0;i<(1<<n);i++){
		int s=0;
		for(int j=0;j<n;j++)if(i>>j&1)s+=a[j];else s-=a[j];
		if(s%360==0){
//			printf("%d\n",s);
			f=0;
		}
	}
	if(f)printf("NO\n");else printf("YES\n");
	return 0;
}