#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int t,n,c[N];
ll sum[N],tot,ans,summ;

inline int check(int l,int r){
	if(summ+sum[r]-sum[l] - (-sum[max(0,l-1)] + tot-sum[r]) >= 0) return 0;
	return 1;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans = summ = tot = 0;
		for(int i=1;i <= n;i++) scanf("%d",&c[i]) , tot += c[i] , sum[i] = sum[max(i-2,0)] + c[i];
		
		for(int i=2;i < n-1;i++){
			if(2*(sum[i]+sum[i-1]) > tot) ans++;
//			if(2*()
		}
	
		for(int i=0;i <= n;i++){
			summ += c[i];
			
			int l = i,r = ((n-i)&1) ? n-1 : n,anss = l-2;
			while(l <= r){
				int mid = (l+r)>>1;
				if((mid-i)&1) mid--;
				if(check(i,mid)) anss = mid , l = mid+2;
				else r = mid-2;
			}
			ans += (anss-i)/2+1;
						
			summ += 2*c[n];
			l = i,r = ((n-3-i)&1) ? n-4 : n-3,anss = l-2;
			while(l <= r){
				int mid = (l+r)>>1;
				if((mid-i)&1) mid--;
				if(check(i,mid)) anss = mid , l = mid+2;
				else r = mid-2;
			}
			ans += (anss-i)/2+1;

			if(i > 2){
				summ -= 2*c[1];
				l = i,r = ((n-3-i)&1) ? n-4 : n-3,anss = l-2;
				while(l <= r){
					int mid = (l+r)>>1;
					if((mid-i)&1) mid--;
					if(check(i,mid)) anss = mid , l = mid+2;
					else r = mid-2;
				}
				ans += (anss-i)/2+1;
	
				summ -= 2*c[n];
				l = i,r = ((n-i)&1) ? n-1 : n,anss = l-2;
				while(l <= r){
					int mid = (l+r)>>1;
					if((mid-i)&1) mid--;
					if(check(i,mid)) anss = mid , l = mid+2;
					else r = mid-2;
				}
				ans += (anss-i)/2+1;

				summ += 2*c[1];
			}
			else summ -= 2*c[n];
			
		}
		
		printf("%lld\n",ans%998244353);	
	}
	
}