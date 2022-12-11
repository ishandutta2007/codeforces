#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;
typedef unsigned long long ull;

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

const int N = 1e6+5;
const int P = 1e9+7;

int n;
char s[N];
map<ull,int>st;
int f[N];
ull pre[N],mi[N];

ull haxi(int l,int r){
	if (l>r)return 0;
	return pre[r]-pre[l-1]*mi[r-l+1];
}

int main(){
	n=get();
	scanf("%s",s+1);
	st.clear();
	fo(i,1,n)pre[i]=pre[i-1]*P+s[i]-'a'+1;
	mi[0]=1;
	fo(i,1,n)mi[i]=mi[i-1]*P;
	int ans=0;
	fd(i,n,1){
		f[i]=min(n-i+1,f[i+1]+2);
		for(;f[i];f[i]--){
			if (st[haxi(i,i+f[i]-1)]>i+f[i])break;
			if (f[i]<n-i+1&&st[haxi(i+1,i+f[i])]>i+f[i])break;
		}
		f[i]=min(f[i]+1,n-i+1);
		ans=max(ans,f[i]);
		fd(len,f[i],1){
			ull t=haxi(i,i+len-1);
			if (!st[t])st[t]=i;
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}