#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int n;
INT num,m;

#define NN 1000011
int chk[NN];
void init() {
	chk[1] = 1;
	for (int i=2; i<sqrt(NN); i++)
		if (!chk[i]) 
			for (int j=2; i*j<NN; j++) chk[i*j] = 1;
}

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	init();
	cin>>n;
	for (int i=0; i<n; i++) {
		scanf("%I64d",&num);
		m = (INT)(sqrt(num)+1e-8);
		if ( m * m != num)  puts("NO");
		else {
			if (!chk[m]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}