#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,k;
bool t[2000050];

int main(){
	fill(t, t+2000050, false);
	scanf("%d%d%d",&n,&m,&k);
	int tmp;
	for(int i = 0; i < n; i++) scanf("%d", &tmp), t[tmp] = true;
	int l = 0, r = 0;
	int cnt = 0;
	int res = 0;
	while(r < m-1){
		r++;
		if(t[r]) cnt++;
		if(cnt >= k) cnt--, t[r] = false, res++;
		
	}
	//cout << cnt;
	
	while(r < 2000001){
		r++, l++;
		if(t[l-1]) cnt--;
		if(t[r]) cnt++;
		if(cnt >= k) cnt--, t[r] = false, res++;
	}
	cout << res;
}