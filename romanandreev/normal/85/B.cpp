#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int k[4];
int t[4];
int n,yk;
ll ans;
ll en[1000000];
ll men[1000000];
int c[1000000];
ll c1[1000000];
ll c2[1000000];

int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d%d%d",&k[0],&k[1],&k[2]);
	scanf("%d%d%d",&t[0],&t[1],&t[2]);
	scanf("%d",&n);
	for (int i=0;i<3;i++){
		k[i]=min(k[i],n);
	}
	for (int i=0;i<n;i++){
		scanf("%d",&c[i]);		
	}
	yk=0;
	for (int i=0;i<n;i++){
		en[yk]=max(en[yk],(ll)c[i])+t[0];
		men[i]=en[yk];
		yk=(yk+1)%k[0];
	}
	for (int i=0;i<n;i++){
		en[i]=0;
		c1[i]=men[i];
	}
	yk=0;
	for (int i=0;i<n;i++){
		en[yk]=max(en[yk],c1[i])+t[1];
		men[i]=en[yk];
		yk=(yk+1)%k[1];
	}
	for (int i=0;i<n;i++){
		en[i]=0;
		c2[i]=men[i];
	}
	yk=0;
	for (int i=0;i<n;i++){
		en[yk]=max(en[yk],c2[i])+t[2];
		men[i]=en[yk];
		yk=(yk+1)%k[2];
	}
	ans=0;
	for (int i=0;i<n;i++){
		ans=max(ans,men[i]-c[i]);
	}
	cout<<ans<<endl;


    return 0;
}