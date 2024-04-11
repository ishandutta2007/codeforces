#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN];
char A[MN],B[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s%s",A+1,B+1);
		int lst=-1,r=0;
		for(int i=1;i<=n;++i){
			if(A[i]!=B[i]){
				if(lst==0)r++;
				r+=2,lst=-1;
			}
			else{
				if(A[i]=='0'){
					if(lst==0) r++;
					else if(lst==1){
						r+=2;
						lst=-1;
					}
					else lst=0;
				}
				if(A[i]=='1'){
					if(lst==0)r+=2,lst=-1;
					else lst=1;
				}
			}
		}
		if(lst==0)r++;
		printf("%lld\n",r);
	}
	return 0;
}