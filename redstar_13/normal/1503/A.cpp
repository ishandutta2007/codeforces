#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 202020;

char A[NN], B[NN], s[NN];

int solve(int n) {
	if(n&1) return puts("NO"), 0;
	int ones=0, ok=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='1') ones++;
		else if(ok==0) A[i]='(', B[i]=')', ok^=1;
		else A[i]=')', B[i]='(', ok^=1;
	}
	for(int i=0; i<n; i++) if(s[i]=='1') {
		A[i]=B[i]=ones>1?'(':')';
		ones-=2;
	}
	A[n]=B[n]=0;
	int ca=0, cb=0;
	for(int i=0; i<n; i++) {
		if(A[i]=='(') ca++;
		else ca--;
		if(ca<0) return puts("NO"), 0;
		if(B[i]=='(') cb++;
		else cb--;
		if(cb<0) return puts("NO"), 0;
	}
	puts("YES");
	puts(A);
	puts(B);
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int T, n;
	for(cin>>T; T--; ) {
		scanf("%d", &n);
		scanf("%s", s);
		solve(n);
	}
}