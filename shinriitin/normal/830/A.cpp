#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 1005
typedef pair<int,int>pii;

int n,k,p,a[max_N],b[max_N<<1];

pair<int,int>seg[max_N];

inline int Abs(int x){
	return x<0?-x:x;
}

priority_queue<pii,vector<pii>,greater<pii> >s;

inline bool check(int len){
	for(int i=1;i<=n;++i){
		int j=1;
		while(j<=k&&Abs(a[i]-b[j])+Abs(p-b[j])>len)++j;
		if(j>k)return 0;
		seg[i].first=j;
		j=k;
		while(j&&Abs(a[i]-b[j])+Abs(p-b[j])>len)--j;
		seg[i].second=j;
	}
	sort(seg+1,seg+1+n);
	while(!s.empty())s.pop();
	for(int i=1,j=1,cnt=0;i<=k;++i){
		while(j<=n&&seg[j].first==i){
			s.push(make_pair(seg[j].second,j));
			++j;
		}
		if(!s.empty()){
			pii x=s.top();
			s.pop();
			if(x.first<i)return 0;
			if(++cnt==n)return 1;
		}
	}
	return 0;
}

int main(){
	n=gint(),k=gint(),p=gint();
	for(int i=1;i<=n;++i)a[i]=gint();
	for(int i=1;i<=k;++i)b[i]=gint();
	sort(b+1,b+1+k);
	int l=0,r=2e9;
	while(l<r){
		int mid=(1ll*l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}