#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int a[300010],rev[300010],st1[300010][20],pos1[300010][20],st2[300010][20],pos2[300010][20];

inline pair<int,int> query1(int l,int r)
{
	int id=rev[r-l+1];
	if(st1[l][id]<st1[r-(1<<id)+1][id]) return make_pair(st1[l][id],pos1[l][id]);
	else return make_pair(st1[r-(1<<id)+1][id],pos1[r-(1<<id)+1][id]);
}

inline pair<int,int> query2(int l,int r)
{
	int id=rev[r-l+1];
	if(st2[l][id]>st2[r-(1<<id)+1][id]) return make_pair(st2[l][id],pos2[l][id]);
	else return make_pair(st2[r-(1<<id)+1][id],pos2[r-(1<<id)+1][id]);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;(1<<i)<=n;i++){
			for(int j=(1<<i);j<=min((1<<(i+1))-1,n);j++) rev[j]=i;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) st1[i][0]=a[i],pos1[i][0]=i;
		for(int i=1;i<20;i++){
			for(int j=1;j<=n-(1<<i)+1;j++){
				if(st1[j][i-1]<st1[j+(1<<(i-1))][i-1]){
					st1[j][i]=st1[j][i-1];pos1[j][i]=pos1[j][i-1];
				}
				else{
					st1[j][i]=st1[j+(1<<(i-1))][i-1];pos1[j][i]=pos1[j+(1<<(i-1))][i-1];
				}
			}
		}
		for(int i=1;i<=n;i++) st2[i][0]=a[i],pos2[i][0]=i;
		for(int i=1;i<20;i++){
			for(int j=1;j<=n-(1<<i)+1;j++){
				if(st2[j][i-1]>st2[j+(1<<(i-1))][i-1]){
					st2[j][i]=st2[j][i-1];pos2[j][i]=pos2[j][i-1];
				}
				else{
					st2[j][i]=st2[j+(1<<(i-1))][i-1];pos2[j][i]=pos2[j+(1<<(i-1))][i-1];
				}
			}
		}
		int now=1,ans=0;
		while(now!=n){
			ans++;
			if(a[now+1]>a[now]){
				int l=now+1,r=n,pos=now+1;
				while(l<=r){
					int mid=(l+r)/2;
					pair<int,int> val=query1(now+1,mid);
					if(val.first>a[now]){
						pos=mid;l=mid+1;
					}
					else r=mid-1;
				}
				pair<int,int> val=query2(now+1,pos);
				now=val.second;
			}
			else{
				int l=now+1,r=n,pos=now+1;
				while(l<=r){
					int mid=(l+r)/2;
					pair<int,int> val=query2(now+1,mid);
					if(val.first<a[now]){
						pos=mid;l=mid+1;
					}
					else r=mid-1;
				}
				pair<int,int> val=query1(now+1,pos);
				now=val.second;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}