//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxv = 1e4 + 9;
const int cut = 300;
const int Maxn = 1e5 + 2e4 + 9;
int is[Maxv],arr[Maxn],n;
vector<int> v;
int save[Maxn / cut];
int cnt[Maxn / cut][Maxv];
void update(int i,int j,int x,int id) {
	int b = id * cut,e = min((id + 1) * cut - 1,n - 1);
	if(i > e || b > j) return;
	if(i <= b && e <= j) {
		save[id] += x;
		return;
	}
	for(int k = max(b,i); k <= min(e,j);k++) {
		cnt[id][arr[k]]--;
		arr[k] += x;
		cnt[id][arr[k]]++;
	}
	return;
}
int query(int i,int j,int id) {
	int b = id * cut,e = min((id + 1) * cut - 1,n - 1);
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) {
		int res = 0;
		for(int k = 0; k < v.size();k++) {
			int x = v[k];
			if(save[id] > x) break;
			res += cnt[id][x - save[id]];
		}
		return res;
	}
	int res = 0;
	for(int k = max(b,i); k <= min(e,j);k++) {
		if(is[arr[k] + save[id]]) res++;
	}
	return res;
}
int main() {
	int q; scanf("%d%d",&n,&q);
	for(int i = 0; i < n;i++) scanf("%d",&arr[i]);
	for(int i = 0; i * cut < n;i++) {
		for(int j = i * cut; j < min((i + 1) * cut,n);j++) {
			cnt[i][arr[j]]++;
		}
	}
	for(int i = 0; i < Maxv;i++) {
		int x = i;
		is[i] = 1;
		while(x) {
			if(x % 10 != 4 && x % 10 != 7) is[i] = 0;
			x /= 10;
		}
		if(is[i]) {
			v.push_back(i);
		} 
	}
	reverse(v.begin(),v.end());
	while(q--) {
		char p[10];
		scanf("%s",&p);
		if(p[0] == 'c') {
			int l,r; scanf("%d%d",&l,&r);
			--l,--r;
			int cnt = 0;
			for(int i = 0;i * cut < n;i++) {
				cnt += query(l,r,i);
			}
			printf("%d\n",cnt);
		} else {
			int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r;
			for(int i = 0; i * cut < n;i++) {
				update(l,r,x,i);
			}
		}
	}
	return 0;
}