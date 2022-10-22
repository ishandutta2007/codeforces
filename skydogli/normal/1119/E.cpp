#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
int n,a[300005];
int main(){
	n=read();
	int cnt=0;
	LL sum=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]/2>=cnt){
			sum+=cnt;
			a[i]-=cnt*2;
			sum+=a[i]/3;
			cnt=a[i]%3;
		}
		else{
			sum+=a[i]/2;
			cnt-=a[i]/2;
			cnt+=a[i]%2;
		}
//		cerr<<i<<": "<<sum<<" cnt: "<<cnt<<endl;
	}
	printf("%lld\n",sum);
	return 0;
}