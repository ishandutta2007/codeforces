#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

bool good[1005];
string a,b,c,d;
int k;

int main(){
	fill(good, good+1005, true);
	int n,m;
	scanf("%d%d", &n, &m);
	getchar();
	for(int t = 0; t < m; t++){
		cin >> a >> b >> c >> d >> k;
		if(c == "left"){
			for(int i = k; i <= n; i++) good[i] = false;
		}
		else{
			for(int i = 0; i <= k; i++) good[i] = false;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(good[i]) ans ++;
	}
	if(ans == 0) printf("-1");
	else printf("%d", ans);
}