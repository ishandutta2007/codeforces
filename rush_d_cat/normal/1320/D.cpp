#include <bits/stdc++.h>
using namespace std;
const int N=400000+10;

namespace SA {
	char s[N];int n;
	int height[N],rk[N],sa[N],cc[N],t1[N],t2[N];
	bool cmp(int *y,int a,int b,int k){
	    int a1=y[a],a2=a+k>=n?-1:y[a+k];
	    int b1=y[b],b2=b+k>=n?-1:y[b+k];
	    return a1==b1&&a2==b2;
	}
	void buildSA(int m) {
	    int *x=t1,*y=t2;
	    for(int i=0;i<m;i++) cc[i]=0;
	    for(int i=0;i<n;i++) cc[x[i]=s[i]]++;
	    for(int i=1;i<m;i++) cc[i]+=cc[i-1];
	    for(int i=n-1;i>=0;i--) sa[--cc[x[i]]]=i;
	    for(int k=1;k<=n;k<<=1) {
	        int p=0;
	        for(int i=n-k;i<n;i++) y[p++]=i;
	        for(int i=0;i<n;i++)
	            if(sa[i]>=k) y[p++]=sa[i]-k;

	        for(int i=0;i<m;i++) cc[i]=0;
	        for(int i=0;i<n;i++) cc[x[y[i]]] ++;
	        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
	        for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];
	        swap(x,y);
	        m=1,x[sa[0]]=0;
	        for(int i=1;i<n;i++) {
	            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?m-1:m++;
	        }
	        if(m>=n) break;
	    }
	}
	void buildH(){
	    for(int i=0;i<n;i++)
	        rk[sa[i]]=i;
	    int k=0; height[0]=0;
	    for(int i=0;i<n;i++) {
	        if(!rk[i]) continue;
	        if(k) k--;
	        int j=sa[rk[i]-1];
	        while(s[i+k]==s[j+k]) k++;
	        height[rk[i]]=k;
	    }
	}
	void init() {
	    //scanf("%s", s); 
	    //printf("$ %s\n", s);
	    n=strlen(s);
	    buildSA(1000); buildH();
	}
	int LG[N],st[N][20];
	void RmqInit() {
	    for(int i=1;i<N;i++) {
	        int t = i, c = 0;
	        while(t>1) { t/=2; c ++; }
	        LG[i] = c;
	    }
	    for(int i=0;i<n;i++)
	        st[i][0]=height[i];

	    for(int i=1;i<20;i++)
	    for(int j=0;j<n;j++)
	        if(j+(1<<i)<=n)
	            st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
	}

	int LCP(int x, int y) { // suffix(x) & suffix(y)
	    if (x==y) return n-x;
	    int l = min(rk[x], rk[y]) + 1;
	    int r = max(rk[x], rk[y]); 
	    int k = LG[r-l+1];
	    return min(st[l][k], st[r-(1<<k)+1][k]);
	}
}

int n,q;
char str[N]; int sum[N],s0[N];
int main() {
	scanf("%d%s",&n,str+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(str[i]=='1'?1:0);
		s0[i]=s0[i-1]+(str[i]=='0'?1:0);
	}
	SA::n = 0;
	for(int i=1;i<=n;i++){
		if(str[i]=='0') {
			SA::s[SA::n++]=(sum[i]%2+'0');
		}
	}
	int A=SA::n;
	for(int i=1;i<=n;i++){
		if(str[i]=='0') {
			SA::s[SA::n++]=(((sum[i]%2)^1)+'0');
		}
	}	
	SA::init();
	SA::RmqInit();
	//printf("# %s\n", SA::s);
	scanf("%d",&q);
	while(q--){
		int l,r,len; scanf("%d%d%d",&l,&r,&len);
		if(s0[r+len-1]-s0[r-1] != s0[l+len-1]-s0[l-1]) {
			printf("No\n"); continue; 
		}
		int cnt=s0[r+len-1]-s0[r-1];
		int pos1=s0[l-1], pos2=s0[r-1];
		if(sum[l-1]%2==sum[r-1]%2)
			printf("%s\n", SA::LCP(pos1,pos2)>=cnt?"Yes":"No");
		else
			printf("%s\n", SA::LCP(pos1,pos2 + A)>=cnt?"Yes":"No");
	}
}