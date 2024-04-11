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
bool chk(int a){
	if(a==1)return 0;
	for(int i=2;i*i<=a;++i)
		if(a%i==0)return 0;
	return 1;
}
bool DIV(int a){
	for(int i=2;i*i<=a;++i){
		if(a%i==0){
			if(chk(a/i))return 1;
			return 0;
		}
	}
	return 0;
}
int main(){
	int n=read();
	int i;
	for(i=2;i<=n;i++){
		if(n%i==0){printf("%d",i);n/=i;i--;}
	}
	return 0;
}