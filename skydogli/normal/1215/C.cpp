#include<bits/stdc++.h>
using namespace std;
#define MN 200015
char c1[MN],c2[MN];
int loca[MN],locb[MN],A,B,n;
int main(){
	scanf("%d%s%s",&n,c1+1,c2+1);
	for(int i=1;i<=n;++i){
		if(c1[i]=='a'&&c2[i]=='b')loca[++A]=i;
		if(c1[i]=='b'&&c2[i]=='a')locb[++B]=i;
	}
	if(abs(A-B)%2!=0)puts("-1");
	else {
//		int res=A/2+B/2;
		printf("%d\n",A/2+B/2+(A&1)*2);
		for(int i=2;i<=A;i+=2){
			printf("%d %d\n",loca[i-1],loca[i]);
		}
		for(int i=2;i<=B;i+=2){
			printf("%d %d\n",locb[i-1],locb[i]);
		}
		if(A&1){
			printf("%d %d\n",loca[A],loca[A]);
			printf("%d %d\n",loca[A],locb[B]);
		}
	}
	return 0;
}