#include<bits/stdc++.h>
#define INPUT_LEN 1000
using namespace std;
bitset<4000> s[2000];
int a[500000], b[500000];
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}

main() {
	int n, m, i, j; gn(n), gn(m);
	for(i=m; i--; ) {
		gn(a[i]), gn(b[i]);
		s[--a[i]].set(--b[i]);
	}
	
	for(i=0; i<n; i++) s[i].set(n+i);
	for(i=0; i<n; i++) {
		if(!s[i][i]) {
			for(j=i+1; j<n; j++) if(s[j][i]) {
				swap(s[i], s[j]);
				break;
			}
		}
		for(j=i+1; j<n; j++) if(s[j][i]) s[j]^=s[i];
	}
	for(i=n; i--; ) for(j=i; j--; ) if(s[j][i]) s[j]^=s[i];
	
	for(int i=m; i--; ) puts(s[b[i]][n+a[i]] ? "NO" : "YES");
}