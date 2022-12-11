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

const int N = 2e6+5;

int n;
int a[N];
int cnt[N][2];

int main(){
	LL ans=0;
	n=get();
	fo(i,1,n){
		a[i]=get();
		a[i]^=a[i-1];
	}
	cnt[0][0]++;
	fo(i,1,n){
		ans+=cnt[a[i]][i&1];
		cnt[a[i]][i&1]++;
	}
	cout<<ans<<endl;
	return 0;
}