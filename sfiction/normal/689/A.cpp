#include <cstdio>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

PII getPos(int x){
	return x == 0 ? PII(3, 1) : PII((x - 1) / 3, (x - 1) % 3);
}

int main(){
	int n;
	char s[20];
	scanf("%d", &n);
	scanf("%s", s);
	PII s0 = getPos(s[0] - '0');
	int cnt = 0;
	for (int i = 0; i < 10; ++i){
		PII ns = getPos(i);
		bool flag = true;
		for (int j = 0; j < n; ++j){
			PII t = getPos(s[j] - '0');
			t.st = ns.st + t.st - s0.st;
			t.nd = ns.nd + t.nd - s0.nd;
			flag &= t.st == 3 && t.nd == 1 || 0 <= t.st && t.st < 3 && 0 <= t.nd && t.nd < 3;
		}
		cnt += flag;
	}
	puts(cnt == 1 ? "YES" : "NO");
	return 0;
}