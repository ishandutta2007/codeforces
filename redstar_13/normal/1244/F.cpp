#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 200011;
int n, k;
char s[NN];
char t[NN];
char ans[NN];

int solve() {
	cin >> n >> k;
	scanf("%s", s);
	int ok = 0;
	int p =1;
	for(int i=0; s[i]; i++) {
		if(s[i] == s[(i+1)%n]) ok=1, p =(i+1)%n;
	}
	if(ok == 0) {
		for(int i=0; s[i]; i++) {
			if(k%2==0) putchar(s[i]);
			else putchar('0'+'1'-s[i]);
		}
		return puts("");
	}
	
	for(int i=0; i<n; i++) t[i] = s[(p+i)%n];
	for(int i=0; i<n; i++) s[i] = t[i];
	for(int i=0, j=0; j<n; i=j-1) {
		while(s[j] == s[i]) ans[j]=s[j], j++;
		i=j-1;
		while(j<n and s[j]!=s[j-1]) j++;
		int len=j-i;
		if(s[i] == s[j-1]) {
			int pst=i+k, ped=j-1-k;
			for(int r=i; r<=j-1 and r<=pst; r++) ans[r]=s[i];
			for(int r=max(i, ped); r<=j-1; r++) ans[r]=s[i];
			char c=s[i];
			for(int r=pst+1; r<ped; r++) {
				c='W'+'B'-c;
				ans[r]=c;
			}
		}
		else {
			int pst=i+k, ped=j-1-k;
			if(pst>(i+j-1)/2) pst=(i+j-1)/2;
			if(ped<(i+j-1)/2+1) ped=(i+j-1)/2+1;
			for(int r=i; r<=pst; r++) ans[r]=s[i];
			for(int r=max(i, ped); r<=j-1; r++) ans[r]=s[j-1];
			char c=s[i];
			for(int r=pst+1; r<ped; r++) {
				c='W'+'B'-c;
				ans[r]=c;
			}
		}
	}
	for(int i=n-p; i<n; i++) putchar(ans[i]);
	for(int i=0; i<n-p;i++) putchar(ans[i]);
	puts("");
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
solve();
	return 0;
}