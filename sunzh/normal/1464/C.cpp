#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline long long llread(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3ll)+(x<<1ll)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
long long k;
char str[100010];
int main(){
	n=read(),k=llread();
	scanf("%s",str+1);
	k-=(1<<(str[n]-'a'));k+=(1<<(str[n-1]-'a'));
	vector<int>v;
	for(int i=1;i<n-1;++i) k+=(1<<str[i]-'a'),v.pb(1<<(str[i]-'a'+1));
	sort(v.begin(),v.end());
	for(int i=n-2;i>=1;--i){
		if(k>=v.back()) k-=v.back();
		v.pop_back();
	}
	printf(k==0?"Yes\n":"No\n");
	return 0;
}