#include <bits/stdc++.h>
using namespace std;
const int N=102;
typedef long long LL;

int t,n,m;
char s[N][N];

LL id(int m, char s[]) {
	LL ans=0;
	for(int i=1;i<=m;i++){
		if(s[i]=='1'){
			ans+=1LL<<(m-i);
		}
	}
	return ans+1;
}

void prt(LL x) {
	x--;
	for(int i=1;i<=m;i++){
		if(1LL<<(m-i) <= x) {
			printf("1"); x-=((1LL<<(m-i)));
		}else{
			printf("0");
		}
	}
	printf("\n");
}
vector<LL> vec;
LL f(LL x) {
	int cnt=0;
	for(auto y: vec) if (y<=x) cnt++;
	return x-cnt;
}



int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		vec.clear();
		for(int i=1;i<=n;i++){
			vec.push_back(id(m, s[i]));
		}
		LL tot = (1LL<<m) - n; 
		LL lef = 0, rig = 1LL<<m;
		while (rig - lef > 1) {
			LL mid = (lef + rig) >> 1;
			if (f(mid) >= (tot + 1) / 2) rig = mid;
			else lef = mid;
		}
		prt(rig);
	}
}