#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<unordered_map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int nw;
unordered_map<int,bool>Map;
bool query(int x){
	if(x==0) return 1;
	// if(Map.count(x)) return Map[x];
	printf("\n? %lld\n",x);fflush(stdout);
	char str[11];scanf("%s",str+1);
	if(str[1]=='L') nw+=x;else nw-=x;
	if(nw<0) printf("FUCK\n");
	return (str[1]=='L');
}
int fib[100010];
void calc(int l,int r){
    if(r-l<15){
        for(int i=l+1;i<=r;++i){
            if(!query(i)){
	printf("\n! %lld\n",i-1);fflush(stdout);return ;
            }
        }
	printf("\n! %lld\n",r);fflush(stdout);return ;
    }
	int T=l;
	int res=l;
	int c=0;
	++l;
	while(l<=r){
		int mid=(l*3+r*(c+1))/(c+4);
		while(nw<mid) query(res);
		if(query(mid)) l=mid+1,res=mid,++c;else r=mid-1,c=max(c-1,0ll);
	}
	printf("\n! %lld\n",res);fflush(stdout);
}
int T;
signed main(){
	T=read();
	while(T--){
		nw=1;Map.clear();
		fib[0]=1;fib[1]=1;
		if(!query(1)){
			printf("\n! 0\n");fflush(stdout);continue ;
		}
		const int t=1e14;
		for(int i=2;;++i){
			fib[i]=nw;
			fib[i]=min(fib[i],t);
			if(query(fib[i])){
				if(fib[i]==t){
					printf("\n! %lld\n",t);fflush(stdout);break ;
				}
				continue ;
			}
			else{
				query(fib[i-1]);
				query(fib[i-1]);
				// query(fib[i-1]);
				calc(fib[i-1],fib[i]-1);break ;
			}
		}
	}
}