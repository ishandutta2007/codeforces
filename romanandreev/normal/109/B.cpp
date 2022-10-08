#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<cassert>
#include<ctime>
#include<climits>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define y1 y1_fudisghsdis
#define y0 y0_fudisghsdis
#define ws ws_fudisghsdis
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define uniq(a) {sort(all(a));(a).resize(unique(all(a))-(a).begin());}
#define uniq1(a,n) {sort(a,a+n);n=unique(a,a+n)-a;}

typedef pair<int,int> pi;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#ifdef WIN32 
	#define INT64 "%I64d"
#else
	#define INT64 "%lld"	
#endif

int main(){
	#ifdef home
	assert(freopen("output.txt","w",stdout));
	assert(freopen("input.txt","r",stdin));
	#endif
	ll pl,pr,vl,vr,k;
	vector<ll> v;
	cin>>pl>>pr>>vl>>vr>>k;
	for (int i=1;i<=10;i++){
		for (int j=0;j<(1<<i);j++){
			ll x=0;
			for (int k=0;k<i;k++){
				if (j&(1<<k)){
					x=x*10+7;
				} else
					x=x*10+4;
			}
			v.pb(x);
		}
	}
	v.pb(0);
	v.pb((int)1e9+1);
	sort(all(v));
	ll ans=0;
	for (int i=1;i<=sz(v)-k;i++){
		ans+=max(0LL,(min(v[i],pr)-max(pl,v[i-1]+1)+1))*max(0LL,(min(vr,v[i+k]-1)-max(v[i+k-1],vl)+1));
	}
	for (int i=1;i<=sz(v)-k;i++){
		ans+=max(0LL,(min(v[i],vr)-max(vl,v[i-1]+1)+1))*max(0LL,(min(pr,v[i+k]-1)-max(v[i+k-1],pl)+1));
	} 
	if (k==1){
		for (int i=1;i<=sz(v)-2;i++){
			if (v[i]>=pl && v[i]<=pr && v[i+k-1]<=vr && v[i+k-1]>=vl){
				ans--;
			}
		}
	}
	printf("%.12lf\n",(double)((ans*((ld)1.0))/(((ll)pr-pl+1)*((ll)vr-vl+1))));
	#ifdef home
		cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	#endif
	return 0;
}