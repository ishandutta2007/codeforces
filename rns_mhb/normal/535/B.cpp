#include<bits/stdc++.h>
using namespace std;
int f[11], cnt, sum, ans[100000], n;
void cal(int k,int t){
	if(k == t){
		int p = 1, sum = 0;
		for(int i = 0;i < t;i ++){
			if(f[i] == 0) sum += 4 * p;
			else if(f[i] == 1) sum += 7 * p;
			p *= 10;
		}
		ans[cnt ++] = sum;
		return;
	}
	f[k] = 1;
	cal(k+1,t);
	f[k] = 0;
	cal(k+1,t);
}
main(){
	for(int i = 1;i < 10;i ++) cal(0,i);
 sort(ans,ans + cnt);
 cnt = unique(ans,ans + cnt) - ans;
 scanf("%d",&n);
 for(int i = 0;i < cnt;i ++) if(ans[i] == n) {printf("%d",i+1); break;}
}