#include<bits/stdc++.h>
using namespace std;

#define N 1000010

char ans[2*N], T[2*N], tmp[N];
int s[2 * N], t[2 * N],n, e, len, k, x, mx, mn = 2 * N;

main(){
	scanf("%d\n",&n);
	while(n --){
		scanf("%s %d",tmp,&k);
		len = strlen(tmp);
		strcpy(T+e,tmp);
		e += len;
		while(k--){
			scanf("%d",&x);
			mn = min(x, mn);
			if(x + len - 1 > s[x]) s[x] = x + len - 1,t[x] = e - 1;
			if(x + len - 1 > mx) mx = x + len - 1;
		}
	}
	for(int i = 1;i < mn;i ++) ans[i] = 'a';
	e = mn-1;
	for(int i = mn;i <= mx;i ++){
		if(!s[i] && e >= i) continue;
		if(!s[i] && e < i){e = i, ans[i] = 'a'; continue;}
		if(s[i] > e) {
				for(int j = s[i];j > e;j --) ans[j] = T[t[i]+j-s[i]];
				e = s[i];
		}
	}
	for(int i = 1;i <= mx;i ++) printf("%c",ans[i]);
}