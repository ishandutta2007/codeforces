#include <bits/stdc++.h>
using namespace std;

int a[20], b[20], c[40], aa[20], bb[20], la, lb, oA, oB, A, B, nA, nB, cnt, ans, flag, l, num;
int pact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool vis[10];


int main(){
	scanf("%d %d", &A, &B);
	ans = 0;
	oA = A --, oB = B --;
	cnt = 0, la = 0, lb = 0;
	if(A){
	while(A){
		a[cnt ++] = A % 7;
		A /= 7;
		la ++;
	}
	}
	else la = 1;
	cnt = 0;
	if(B){
	while(B){
		b[cnt ++] = B % 7;
		B /= 7;
		lb ++;
	}
	}
	else lb	= 1;
	l = la + lb;
	if(l > 7)	printf("0");
	else{
		for(int x = 0; x < oA; x ++)
		for(int y = 0; y < oB; y ++){
			int ox = x, oy = y;
			cnt = 0;
			int lx = 0, ly = 0;
			while(x){
				aa[cnt ++] = x % 7;
				x /= 7;
				lx ++;
			}
			cnt = 0;
			while(y){
				bb[cnt ++] = y % 7;
				y /= 7;
				ly ++;
			}
			for(int i = lx; i < la; i ++)	aa[i] = 0;
			for(int i = ly; i < lb; i ++)	bb[i] = 0;
			flag = 0;
			for(int i = 0; i < 9; i ++)	vis[i] = 0;
			for(int i = 0; i < la && !flag; i ++){
				if(vis[aa[i]])	flag = 1;
				else vis[aa[i]] = 1;
			}
			for(int i = 0; i < lb && !flag; i ++){
				if(vis[bb[i]])	flag = 1;
				else vis[bb[i]] = 1;
			}
			if(!flag)	ans ++;
			x = ox, y = oy;
		}
		printf("%d", ans);
	}
}