#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char a[1000001],b[1000001],c[1000001],d[1000001];
int cnt[26];
int gcd(int x,int y){
	return (x%y)?gcd(y,x%y):y;
}
int main(){
	long long n,m;
	cin>>n>>m;
	scanf("%s%s",a,b);
	int la=strlen(a),lb=strlen(b);
	int g=gcd(la,lb);
	long long ans=0;
	for(int i=0;i<g;i++){
		int lc=0,ld=0;
		for(int j=i;j<la;j+=g)
			c[lc++]=a[j];
		for(int j=i;j<lb;j+=g)
			d[ld++]=b[j];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<lc;i++)
			cnt[c[i]-'a']++;
		for(int i=0;i<ld;i++)
			ans+=lc-cnt[d[i]-'a'];
	}
	ans=ans*(long long)(n/(long long)(lb/g));
	cout<<ans<<endl;
	return 0;
}