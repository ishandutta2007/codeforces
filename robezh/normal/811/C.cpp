#include<cstdio>
#include<iostream>
using namespace std;

int n;
int l[5005], r[5005], a[5005];
int part[5005][5005];
bool in[5005];
int dp[5005][5005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i <= 5005; i++) l[i] = -1, r[i] = -1, in[i] = false;
	for(int i = 0; i < n; i++){
		if(l[a[i]] == -1) l[a[i]] = i;
		r[a[i]] = i;
	};
	for(int i = 0; i < n; i++){
		fill(in, in+5005, false);
		int right = -1;
		int pos = i;
		int xor_sum = 0;
		
//		int right = r[a[i]];
//		int pos = i;
//		int xor_sum = a[i];
//		in[a[pos]] = true;
//		if(l[a[pos]] != pos) continue;
//		if(right == i) part[i][i+1] = xor_sum;
		while(pos < n){
			if(l[a[pos]] != pos && !in[a[pos]]) break;
			if(!in[a[pos]]){
				right = max(r[a[pos]], right);
				in[a[pos]] = true;
				xor_sum ^= a[pos];	
			}
			if(pos == right) part[i][pos+1] = xor_sum;//,printf("start = %d, end = %d, xor_sum = %d\n", i, pos, xor_sum);;
			pos++;
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			dp[0][i] = max(dp[0][j] + part[j][i], dp[0][i]);
			
		}
		res = max(res, dp[0][i]); 
	}
	cout << res;
}