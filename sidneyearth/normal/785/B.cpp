#include<bits/stdc++.h>
using namespace std;
int main(){
	int mn_n_r = 0x3f3f3f3f, mn_m_r = 0x3f3f3f3f;
	int mx_n_l = -1, mx_m_l = -1;
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int l, r; scanf("%d%d", &l, &r);
		mn_n_r = min(mn_n_r, r);
		mx_n_l = max(mx_n_l, l);
	}
	int m; scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r; scanf("%d%d", &l, &r);
		mn_m_r = min(mn_m_r, r);
		mx_m_l = max(mx_m_l, l);
	}
	printf("%d\n", max(max(mx_m_l - mn_n_r , mx_n_l - mn_m_r), 0));
	return 0;
}