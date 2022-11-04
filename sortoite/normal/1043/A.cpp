#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 110

int a[NN], n;

inline bool can(int x) {
	INT sa=0, sb=0;
	for(int i=1; i<=n; i++) {
		sa+=a[i];
		sb+=x-a[i];
	}
	return sb>sa;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	
	int st=*max_element(a+1, a+n+1)-1, ed=0x3f3f3f3f;
	while(ed-st>1) {
		int md=st+ed>>1;
		if(can(md)) ed=md;
		else st=md;
	}
	cout<<ed<<endl;
}