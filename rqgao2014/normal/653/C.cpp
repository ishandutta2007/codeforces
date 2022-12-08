#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define inf 1000009
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}

int n,a[150005];
vi wa1,wa2,wa;
set<pii > s;

inline bool check(){
	for(int i=1;i<n;i++){
		if(i&1){
			if(a[i]>=a[i+1]) return 0;
		}
		else{
			if(a[i]<=a[i+1]) return 0;
		}
	}
	return 1;
}

inline bool jud(int x){
	if(x&1) return (a[x]<a[x+1]&&a[x]<a[x-1]);
	else return (a[x]>a[x+1]&&a[x]>a[x-1]);
}

inline void solve(int x,int y){
	swap(a[x],a[y]);
	if(check()) {puts("1");exit(0);}
	swap(a[x],a[y]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=inf;if(n&1) a[n+1]=inf; else a[n+1]=-1;
	for(int i=1;i<n;i++){
		if(i%2==1){
			if(a[i]>=a[i+1]){wa.pb(i),wa.pb(i+1);}
		}
		else{
			if(a[i]<=a[i+1]){wa.pb(i),wa.pb(i+1);}
		}
	}
	
	unique(wa.begin(),wa.end());
//	printf("%d\n",wa.size());
		if(wa.size()>10) {puts("0");return 0;}
		for(int i=0;i<wa.size();i++){
			for(int j=1;j<=n;j++){
				if(j==wa[i]) continue;
				swap(a[j],a[wa[i]]);
				if(jud(j)){
					bool isok=1;
					for(int k=0;k<wa.size();k++)
						if(!jud(wa[k])) {isok=0;break;}
					if(isok) s.insert(mp(min(wa[i],j),max(wa[i],j)));
				}
				swap(a[j],a[wa[i]]);
			}
		}
		printf("%d\n",s.size());
//		set<pii>::iterator it=s.begin();
//		for(;it!=s.end();it++) printf("%d %d\n",(*it).FF,(*it).SS);
//	}
return 0;
}