#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

inline int power(int a, int b, int m, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

long long a[100010], b[100010];
int n;

long long calc(long long L, long long R) {
	long long ans=0;
	
	if(a[1]<L) {
		int t=lower_bound(a+1, a+n+1, L)-a-1;
		ans+=L*t-b[t];
	}
	
	if(a[n]>R) {
		int t=upper_bound(a+1, a+n+1, R)-a;
		ans+=b[n]-b[t-1]-R*(n-t+1);
	}
	
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  long long k;
  cin>>n>>k;
  for(int i=1; i<=n; i++) scanf("%I64d", a+i);
  sort(a+1, a+n+1);
  for(int i=1; i<=n; i++) b[i]=a[i]+b[i-1];
  
  long long st=-1, ed=1000000000, md, ST, ED, md1, md2, t1, t2;
  while(st+1<ed) {
  	md=st+ed>>1;
		ST=1, ED=1000000000;
  	while(ST+1000<ED) {
  		md1=(ST+ST+ED)/3;
  		md2=(ST+ED+ED)/3;
  		t1=calc(md1, md1+md);
  		t2=calc(md2, md2+md);
  		if(t1<t2) ED=md2;
  		else ST=md1;
  	}
  	int ok=0;
  	for(long long i=ST; i<=ED; i++) {
  		if(calc(i, i+md)<=k) {
  			ok=1;
  			break;
  		}
  	}
  	if(ok) ed=md;
  	else st=md;
  }
  cout<<ed<<endl;
  return 0;
}