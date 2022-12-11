#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;

int n;
char s[N];
int a[N];
int pre[20][N];

int main(){
	n=get();
	scanf("%s",s);
	fo(i,0,n-1)a[i]=s[i]-'0';
	fo(i,0,n-1)a[i]^=a[i+1];
	for(int len=2,d=0;len<=n;len<<=1,d++){
		fd(i,n-1,0){
			pre[d][i]=a[i];
			if (i+len<=n-1)pre[d][i]+=pre[d][i+len];
		}
	}
	for(int q=get();q;q--){
		int l=get(),r=get();
		int ans=0;
		for(int len=1,d=0;len<r-l+1;len<<=1,d++){
			int v=pre[d][l+len-1];
			if (r+len<=n-1)v-=pre[d][r+len];
			v=min(v,(r-l+1)/2/len-v);
			ans+=v;
		}
		ans=(ans+1)/2;
		cout<<ans<<endl;
	}
	return 0;
}