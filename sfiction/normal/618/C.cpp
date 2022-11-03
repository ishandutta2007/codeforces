#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

pair<PII, int> a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i].st.st, &a[i].st.nd);
		a[i].nd = i + 1;
	}
	sort(a, a + n);
	PII &u = a[0].st, &v = a[1].st;
	for (int i = 2; i < n; ++i){
		PII &w = a[i].st;
		if ((u.st - w.st) * (ll)(v.nd - w.nd) - (u.nd - w.nd) * (ll)(v.st - w.st) != 0){
			printf("%d %d %d\n", a[0].nd, a[1].nd, a[i].nd);
			break;
		}
	}
	return 0;
}