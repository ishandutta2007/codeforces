#include <bits/stdc++.h>
using namespace std;

int main() {
    ///freopen("2.in", "r", stdin);
    int n, r;
    scanf("%d %d", &n, &r);
    if(n == 1 && r == 1) {
        puts("0");
		puts("T");
		return 0;
    }
    int val = -1, m = -1;
    for(int last = 1; last < r; last ++) if(__gcd(last, r) == 1){
        int x = last, y = r;
        int gas = 0, cnt = 0;
        while(x && y) {
            if(x > y) swap(x, y);
            if(gas) cnt ++;
            gas += y / x;
			y = y % x;
        }
        if(gas != n) continue;
        ///printf("last = %d gas = %d\n", last, gas);
        if(m < cnt) {m = cnt; val = last;}
    }
    if(val == -1) return puts("IMPOSSIBLE");
    string A;
    int x = val, y = r;
	while(x + y > 2) {
        if(x > y) {A += 'B'; x -= y;}
        else {A += 'T'; y -= x;}
	}
	int sz = A.size();
	if(A[sz-1] == 'T') for(int i = 0; i < A.size(); i ++) A[i] = 'T' + 'B' - A[i];
	A += 'T';
	reverse(A.begin(), A.end());
    int cnt = 0;
    for(int i = 0; i < A.size() - 1; i ++) {
		if(A[i] == A[i+1]) cnt ++;
    }
    printf("%d\n", cnt);
	cout <<  A << endl;
}