#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;

int n,m,k;
int a[N],b[N];
char s[N],t[N];
int p[22];
int mn[1<<20], mx[1<<20];

int getint(char * str) {
	char news[22];
	for (int i = 1; i <= k; i ++) {
		news[ p[i] ] = str[i];
	}
	int ans = 0;
	for (int i = 1; i <= k; i ++) {
		ans = ans << 1 | (news[i] == '1');
	}
	return ans;
}
void updmx(int &x, int y){
	x=max(x,y);
}
void updmn(int &x, int y){
	x=min(x,y);
}
int bitcount(int x) {
	int ans=0;
	for(int i=0;i<k;i++)
		if(x>>i&1) ans++;
	return ans;
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}

	for(int i=0;i<1<<k;i++)mn[i]=1e9,mx[i]=-1e9;
	
	int all = (1<<k) - 1;
	// tackle t
	for(int i=1;i<=k;i++)p[i]=i;
	updmx(mx[getint(t) ^ all], 0);
	for(int i=1;i<=n;i++){
		swap(p[a[i]], p[b[i]]);
		updmx(mx[getint(t) ^ all], i);
	}

	// tackle s
	for(int i=1;i<=k;i++)p[i]=i;
	updmn(mn[getint(s) ^ all], 0);
	for(int i=1;i<=n;i++){
		swap(p[a[i]],p[b[i]]);
		updmn(mn[getint(s) ^ all], i);
	}

	for (int bit = 0; bit < k; bit ++) {
	    for (int i = 1; i < (1<<k); i ++) {
	        if ( ((i>>bit) & 1) == 1 )
	        {
	        	mx[i] = max(mx[i], mx[i^(1<<bit)]);
	        	mn[i] = min(mn[i], mn[i^(1<<bit)]);
	        }
	    }
	}

	int bstval = -1, bstL, bstR;
	for(int i=0;i<1<<k;i++){
		if(mx[all ^ i] - mn[all ^ i] >= m){
			if (bitcount(i) >= bstval) {
				bstval = bitcount(i);
				bstR = mx[all ^ i];
				bstL = mn[all ^ i] + 1;
			}
		}
	}
	int s1=0,t1=0;
	for(int i=1;s[i];i++) s1+=(s[i]=='1'?1:0);
	for(int i=1;t[i];i++) t1+=(t[i]=='1'?1:0);
	printf("%d\n", k + 2 * bstval - s1 - t1);
	printf("%d %d\n", bstL, bstR);
}