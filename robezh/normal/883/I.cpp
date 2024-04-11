#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int num[300500];
int n,k;
int pos[300500];

const int INF = 1000000000;

bool check(int diff){
	for(int i = 0; i <= n; i++) pos[i] = 0;
	pos[0] = 1;
	
	int cur = 1;
	if(num[k] - num[1] <= diff) pos[k] = 1;
	
	for(int i = 1; i <= n; i++){
		while(num[i] - num[cur] > diff && cur <= n) cur++;
		while(!pos[cur-1] && cur <= n) cur++;
		if(cur <= i - k + 1) pos[i] = 1;
		else pos[i] = 0;
	}
	
	return pos[n];
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
	sort(num+1, num+n+1);
	
	int l = -2, r = INF, m;
	while(l+1 < r){
		m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m;
	}
	cout << r << endl;	
}