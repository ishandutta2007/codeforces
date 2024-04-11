#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 300000
#define ll long long
int n,cnt,sl,sr;
int sum[Maxn+5];
char s[Maxn+5],tmp[Maxn+5];
vector<int> v;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int pos=0,now=0,mi=0;
	for(int i=1;i<=n;i++){
		now+=s[i]=='('?1:-1;
		if(now<mi){
			mi=now;
			pos=i;
		}
	}
	if(now!=0){
		puts("0");
		puts("1 1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		tmp[i]=s[(pos+i-1)%n+1];
	}
	v.push_back(0);
	for(int i=1;i<=n;i++){
		s[i]=tmp[i];
		sum[i]=sum[i-1]+(s[i]=='('?1:-1);
		if(!sum[i]){
			cnt++;
			v.push_back(i);
		}
	}
	int ans=cnt,L=1,R=1;
	int l,r,t;
	for(int i=1;i<(int)v.size();i++){
		l=v[i-1]+1;
		r=v[i];
		t=0;
		for(int j=l;j<=r;j++){
			t+=(sum[j]==1);
		}
		if(t>ans){
			ans=t;
			L=l;
			R=r;
		}
	}
	v.clear();
	for(int i=1;i<=n;i++){
		if(sum[i]==1){
			v.push_back(i);
		}
	}
	for(int i=1;i<(int)v.size();i++){
		l=v[i-1]+1;
		r=v[i];
		t=cnt;
		if(sum[l]==0){
			continue;
		}
		for(int j=l;j<=r;j++){
			t+=(sum[j]==2);
		}
		if(t>ans){
			ans=t;
			L=l;
			R=r;
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",(L+pos-1)%n+1,(R+pos-1)%n+1);
	return 0;
}