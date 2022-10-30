#include <bits/stdc++.h>
using namespace std;
#define N 101000
vector<int> v[N];

int main() {
    int a, ta, b, tb, h, m;
    int cnt;
	//freopen("1.in", "r", stdin);
	scanf("%d%d", &a, &ta);
	scanf("%d%d", &b, &tb);
	scanf("%02d:%02d", &h, &m);
	int t = h * 60 + m;
	int xx = 300;
	cnt = 0;
	for(int i = xx; i <= 1439; i += b) {
        int en = t + ta;
        if(t >= i + tb || en <= i) continue;
        cnt ++;
	}
	printf("%d\n", cnt);
	return 0;
}