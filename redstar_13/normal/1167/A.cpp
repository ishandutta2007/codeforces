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

int n,T;
char str[110];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int flag;
	cin>>T;
	while(T--) {
		cin>>n>>str; 
		flag=0;
		if (n<11) puts("NO");
		else {
			n=n-11;
			for (int i=0; i<=n; i++) if (str[i]=='8') flag=1;
			if (flag) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}