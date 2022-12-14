#include <bits/stdc++.h>

using namespace std;

int n , m , tot , t , Mx , Mn , L;

char ed[140];

struct seq{
	char s[150];
	int l;
	bool operator < (const seq &t) const {
		return l < t.l;
	}
}a[150] , b[150];

int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%s" , a[i].s + 1);
		a[i].l = strlen(a[i].s + 1);	
	}
	sort(a + 1 , a + n + 1);
	scanf("%s" , ed + 1);
	L = strlen(ed + 1);int cnt = 0;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = i + 1 ; j <= n ; j ++)
	//	if (a[i].l < L) continue;
		if (!strcmp(a[i].s + 1 , a[j].s + 1)) {
			cnt ++;	
			if (cnt > 1) {
				n --;
				for (int j = i + 1 ; j <= n ; j ++) {
					a[j - 1] = a[j]; 
				} 
			} 
		}
			
	}
	int tot = 0 , tag = 0;
	for (int i = 1 ; i <= n ; i ++) {
		tot ++;
		if (a[i].l > L) break;
		if (a[i].l < L) Mn = Mn + 1 + t ; 
		else if (a[i].l == L && tag == 0) Mn = Mn + 1 + t , tag ++;
		Mx = Mx + 1 + t;
		t = 0;
		if (tot == m) tot = 0 , t = 5; 
	}
	printf("%d %d\n" , Mn , Mx);
	return 0;
}