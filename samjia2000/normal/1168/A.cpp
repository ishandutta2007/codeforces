#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;

int n,m;
int a[N];

bool check(int t){
	int v=0;
	fo(i,1,n){
		int l=a[i],r=a[i]+t;
		if (r<m){
			if (r<v)return 0;
			v=max(v,l);
		}
		else{
			if (r>=m+l-1);
			else{
				r=r%m;
				//0..r,l..m-1
				if (r>=v);
				else v=max(v,l);
			}
		}
	}
	return 1;
}

int main(){
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	int ans=1e9,l=0,r=1e9;
	for(;l<=r;){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}