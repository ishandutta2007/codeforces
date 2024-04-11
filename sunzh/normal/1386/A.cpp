#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
map<long long,int>Map;
 
long long Query(long long x){
	Map[x]=1;
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
 
 
long long Guess(long long n){
	long long l=1,r=n-1;
	long long last=1;
	vector<long long>v;
	while(l<=r){
		long long mid=l+r>>1;
		v.pb(mid);
//		printf("mid:%lld\n",mid);
		l=mid+1;
	}
	sort(v.begin(),v.end());
	int t=1;
	for(int i=v.size()-1;i>=0;--i){
		last+=t*v[i];t=-t;
	}
	l=1,r=n-1;
	
	Query(last);
	long long ans=n;
	long long N=n;
	int flag=t;
	while(l<=r){
		long long mid=l+r>>1;
		if(last+flag*mid<=0){
			mid+=flag;
		}
		if(last+flag*mid>N) mid-=flag;
//		printf("mid:%d\n",mid); 
		bool f=Query(last+flag*mid);last=last+flag*mid;flag=-flag;
		if(f){
			r=mid-1,ans=mid;
		}
		else l=mid+1;
	}
	return ans==-1?n:ans;
}
int T;
int main(){
	T=read();
	while(T--){
		Map.clear();
	long long n;
	cin>>n;
	long long res=Guess(n);
	cout<<"= "<<res<<endl;
	}
}