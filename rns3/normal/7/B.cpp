#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 111

struct memory{
	int id, st, en;
} mem;

bool operator < (memory A, memory B) {
	return A.st < B.st;
}

int t, m, len, num;
bool flag[N];
char s[N];
vector <memory> v;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &t, &m);
	v.clear();
	mem.id = 0, mem.st = 0, mem.en = 0;
	v.push_back(mem);
	mem.st = m + 1, mem.en = m + 1;
	v.push_back(mem);
	int cnt = 0;
	while (t --) {
		scanf("%s", s);
		if (s[0] == 'a') {
			scanf("%d", &len);
			bool ok = 0;
			for (int i = 0; i < v.size() - 1; i ++) {
				if (v[i+1].st - v[i].en > len) {
					mem.id = ++cnt, mem.st = v[i].en + 1, mem.en = v[i].en + len;
					v.push_back(mem);
					flag[cnt] = 1;
					sort(v.begin(), v.end());
					ok = 1; break;
				}
			}
			if (ok) printf("%d\n", cnt);
			else puts("NULL");
		}
		else if (s[0] == 'e') {
			scanf("%d", &num);
			if (num >= 1 && num <= cnt && flag[num]) {
				for (int i = 0; i < v.size(); i ++)
					if (v[i].id == num) {
						v.erase(v.begin() + i);
						flag[num] = 0;
						break;
					}
			}
			else puts("ILLEGAL_ERASE_ARGUMENT");
		}
		else {
			for (int i = 1; i < v.size() - 1; i ++) {
				len = v[i].en - v[i].st;
				v[i].st = v[i-1].en + 1, v[i].en = v[i].st + len;
			}
		}
	//	printf("memory = %d : ", v.size() - 2);
	//	for (int i = 1; i < v.size() - 1; i ++) printf("%d ", v[i].id); puts("");
	}
}