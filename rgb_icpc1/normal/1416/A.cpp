#include <bits/stdc++.h>
#define MX 300005

using namespace std;

int n;
int a[MX], rlt[MX], num[MX];
int main(){
//	freopen("in1.txt", "r", stdin);
	int test;
	cin >> test;
	while(test --) {
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d", a + i);
		memset(num, -1, sizeof num);
		for(int i = 0; i < n; i ++) {
			if(num[a[i]] == -1) {
				num[a[i]] = i;
				rlt[a[i]] = i + 1;
			}
			else{
				num[a[i]] = max(num[a[i]], i - rlt[a[i]]);
				rlt[a[i]] = i + 1;
			}
		}
		for(int i = 0; i < n; i ++) {
			num[a[i]] = max(num[a[i]], n - rlt[a[i]]);
		}
//		for(int i = 0; i < n; i ++) cout << num[a[i]] << " ";
//		cout << endl;
		for(int i = 0; i < MX; i ++) rlt[i] = MX + 1;
		for(int i = 0; i < n; i ++) {
			rlt[num[a[i]] + 1] = min(a[i], rlt[num[a[i]] + 1]);
		}
		int now = MX + 1, flg = 0;
		for(int i = 1; i <= n; i ++) {
			if(rlt[i] == MX + 1 && !flg) cout << -1 << " ";
			else{
				flg = 1;
				now = min(now, rlt[i]);
				cout << now << " ";
			}
		}
		cout << endl;
	}
	return 0;
}