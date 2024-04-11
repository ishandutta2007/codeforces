#include<bits/stdc++.h>
	
	using namespace std;
	typedef long long ll;
	const int N = 4e5+10;
	
	int n,a[N],b[N],curmin,curmax,vis[N],num[N],ans,cnt,cntt;
	
	int cal(int v){
		int x = num[v];
		return a[x] == v ? b[x] : a[x];
	}
	
	int main()
	{
		scanf("%d",&n);
		curmin = 1 , curmax = 2*n;
		for(int i=1;i <= n;i++) scanf("%d%d",&a[i],&b[i]) , num[a[i]] = num[b[i]] = i;
		while(curmin+1 < curmax){
			cnt = cntt = 0;
			
			int tmin = curmin+1,tmax = curmax;
			while(1){
				
				int flag = 0;
				
				for(int i=curmin;i < tmin;i++) if(!vis[i]){
					cnt++ , cntt += a[num[i]] == i;
					if(cal(i) > tmax || cal(i) < tmin){
						puts("-1");
						exit(0);
					}
					tmax = cal(i);
					vis[i] = vis[cal(i)] = 1;
					flag = 1;
				}
				curmin = tmin;
	//			if(cal(tmin-1) > curmax) break;
				
				for(int i=curmax;i > tmax;i--) if(!vis[i]){
					cnt++ , cntt += a[num[i]] == i;
					if(cal(i) < tmin || cal(i) > tmax){
						puts("-1");
						exit(0);
					}
					tmin = cal(i);
					vis[i] = vis[cal(i)] = 1;
					flag = 1;
				}
				curmax = tmax;
	//			if(cal(tmax+1) < curmin) break;
	
				if(!flag) break;
			}
			
			ans += min(cntt,cnt-cntt);
		}
		printf("%d\n",ans);
		return 0;
	}