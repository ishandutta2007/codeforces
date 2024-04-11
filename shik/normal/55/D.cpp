// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 2520
using namespace std;
typedef long long LL;
LL dp[20][520][2550];
int pt[20]={1},lcm[520];
int __lcm( int a, int b ) { return a*b/__gcd(a,b); }
void pre_cal() {
	dp[0][0][0]=1;
	int i,j,k,d; LL tmp;
	for ( i=1; i<20; i++ ) pt[i]=pt[i-1]*10%M;
	for ( i=0; i<512; i++ ) {
		lcm[i]=1;
		for ( j=0; j<9; j++ )
			if ( (i>>j)&1 ) lcm[i]=__lcm(lcm[i],j+1);
	}
	for ( i=0; i<18; i++ ) {
		for ( j=0; j<512; j++ )
			for ( k=0; k<M; k++ ) {
				tmp=dp[i][j][k];
				dp[i+1][j][k]+=tmp;
				for ( d=0; d<9; d++ )
					dp[i+1][j|(1<<d)][(k+(d+1)*pt[i])%M]+=tmp;
			}
	}
	//printf("%ld ms\n",clock());
}
LL cal( LL n ) {
	LL r=0;
	char s[50];
	int i,j,k,l,len,dig[50],now=0,msk=0,tmt,xdd,orz;
	sprintf(s,"%I64d",n);
	len=strlen(s);
	for ( i=0; i<len; i++ ) dig[i]=s[len-i-1]-'0';
	for ( i=len-1; i>=0; i-- ) {
		for ( j=0; j<dig[i]; j++ ) {
			if ( j!=0 ) tmt=msk|(1<<(j-1));
			else tmt=msk;
			for ( k=0; k<512; k++ ) {
				orz=tmt|k;
				xdd=(lcm[orz]-(now+j*pt[i])%lcm[orz])%lcm[orz];
				r+=dp[i][k][xdd];
				for ( l=(xdd+lcm[orz])%M; l!=xdd; l=(l+lcm[orz])%M ) r+=dp[i][k][l];
			}
		}
		now=(now+dig[i]*pt[i])%M;
		if ( dig[i] ) msk|=(1<<(dig[i]-1));
	}
	return r;
}
bool chk( int n ) {
	int m=n;
	while ( m ) {
		if ( m%10!=0 && n%(m%10)!=0 ) return 0;
		m/=10;	
	}	
	return 1;
}
int cal_2( int n ) {
	int i,r=0;
	for ( i=0; i<n; i++ )
		if ( chk(i) ) r++;
	return r;
}
int main()
{
	pre_cal();
	//int n;
	//while ( ~scanf("%d",&n) ) printf("%lld %d\n",cal(n),cal_2(n));
	int t; LL L,R;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%I64d%I64d",&L,&R);
		printf("%I64d\n",cal(R+1)-cal(L));	
	}
	return 0;
}