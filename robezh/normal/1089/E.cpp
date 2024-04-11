#include<bits/stdc++.h>
using namespace std;

int n;
int order[80] = {0,1,2,3,4,5,6,7,
	15,14,13,12,11,10,9,8,
	16,17,18,19,20,21,22,23,
	31,30,29,28,27,26,25,24,
	32,33,34,35,36,37,38,39,
	47,46,45,44,43,42,41,40,
	48,56,57,49,50,58,59,51,
	52,60,61,53,54,62,63};
int full[80] = {0,1,2,3,4,5,6,7,
	15,14,13,12,11,10,9,8,
	16,17,18,19,20,21,22,23,
	31,30,29,28,27,26,25,24,
	32,33,34,35,36,37,38,39,
	47,46,45,44,43,42,41,40,
	48,55,54,53,52,51,50,49,57,56,58,59,60,61,62,63};
int vis[80];

void print(int id) {
	int x = id/8, y = id%8;
	printf("%c%d ",y+'a',x+1);
}

int main() {
	scanf("%d",&n);
	if(n == 63) {
		for(int i=0;i<=n;i++) print(full[i]);
	}
	else {
		for(int i=0;i<=n-2;i++) {
			vis[order[i]] = 1;
			print(order[i]);
		}
		int last = order[n-2];
		if(last/8 == 7) {
			print(last+1);
			print(63);
		}
		else if(last%8 == 7) {
			print(last+8);
			print(63);
		}
		else {
			if(!vis[last%8+56]) print(last%8 + 56);
			else print((last/8) * 8 + 7);
			print(63);
		}
	}
}