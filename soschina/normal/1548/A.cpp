#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 1;

int n, m, q, u, v, opt, cnt[N];
int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(!cnt[u]) n--;
		cnt[u]++;
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		switch(opt){
			case 1:
				scanf("%d%d", &u, &v);
				if(u > v) swap(u, v);
				if(!cnt[u]) n--;
				cnt[u]++;
				break;
			case 2:
				scanf("%d%d", &u, &v);
				if(u > v) swap(u, v);
				cnt[u]--;
				if(!cnt[u]) n++;
				break;
			case 3:
				printf("%d\n", n);
		}
	}
	return 0;
}