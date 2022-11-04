#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 1010

char s[NN];
int ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%s", s+1);
	int n=strlen(s+1);
	
	int flag=1;
	for(int i=n; i>=1; i--) {
		if(flag) {
			if(s[i]=='a') ans[i]=1, flag^=1;
		}
		else {
			if(s[i]=='b') ans[i]=1, flag^=1;
		}
	}
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}