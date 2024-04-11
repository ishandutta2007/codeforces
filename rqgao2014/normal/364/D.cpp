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
#define debuge puts("isok");
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
#include<ctime>
inline void read(ll &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

int n,tot,res[10005];
ll a[1000005],b[1000005],d[10005];

int getpos(ll a){
	int l=1,r=tot;
	while(l<r){
		int mid=l+r>>1;
		if(d[mid]>=a) r=mid; else l=mid+1;
	}
	return r;
}

int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	int T=10;
	ll g=1;
	for(;T--;){
		ll x=a[((rand()<<10)+rand())%n+1];tot=0;
		memset(res,0,sizeof(res));
		for(ll i=1;i*i<=x;i++){
			if(x%i==0){
				d[++tot]=i;
				if(x/i!=i) d[++tot]=x/i;
			}
		}
//		if((ll)sqrt(x)*(ll)sqrt(x)==x) tot--;
		sort(d+1,d+tot+1);
		for(int i=1;i<=n;i++){
			b[i]=gcd(a[i],x);
//			cout<<b[i]<<" "<<getpos(b[i])<<endl;
			res[getpos(b[i])]++;
		}
		
		for(int i=tot;i;i--){
			int tmp=0;
			for(int j=i;j<=tot;j++)
				if(d[j]%d[i]==0) tmp+=res[j];
			if(tmp>=(n+1)/2){g=max(g,d[i]);break;}
		}
	}
	cout<<g<<endl;
	return 0;
}