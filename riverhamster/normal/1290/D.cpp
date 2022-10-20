#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
const int N = 1030;
int n, k, step;
int askCnt = 0;
bool ask(int x){
	/**/static char s[20];
	printf("? %d\n", x); fflush(stdout);
	scanf("%s", s);
	assert(s[0] != 'E');
	if(s[0] == 'Y') return true;
	return false;
	++askCnt;
	return false;
}
void reset(){
	static int resCnt = 0;
	++resCnt;
	assert(resCnt <= 30000);
	puts("R"); fflush(stdout);
}
void report(int x){
	printf("! %d\n", x); fflush(stdout);
}

bool rep[N];

void ask_block(int x){
	int l = step * (x - 1) + 1;
	for(int i=l; i<l+step; i++){
		if(ask(i)) rep[i] = true;
	}
}

int main(){
	scanf("%d%d", &n, &k);
	if(k == 1){
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++){
				ask(i);
				if(ask(j)) rep[j] = true;
			}
		int res = 0;
		for(int i=1; i<=n; i++) res += !rep[i];
		printf("! %d\n", res); fflush(stdout);
		return 0;
	}
	step = k / 2;
	int blocks = n / step;
	// printf("blocks = %d\n", blocks);
	for(int len=1; len<blocks; len++){
		for(int s=1; s<=len; s++){
			if(s + len > blocks) break;
			reset();
			for(int i=s; i<=blocks; i+=len) ask_block(i);
		}
	}
	int res = 0;
	for(int i=1; i<=n; i++) res += !rep[i];
	printf("! %d\n", res); fflush(stdout);
	return 0;
}