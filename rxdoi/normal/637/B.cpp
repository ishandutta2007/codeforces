// by 
// program sky  :)

#include <map>
#include <cstdio>
#include <string>

#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)

using namespace std;

int n;
char a[200005][15];
map<string,bool>bo;

int main(){
// say hello
	scanf("%d",&n);
	For(i,1,n)scanf("%s",a[i]);
	dto(i,n,1){
		string ss=(string)a[i];
		if(!bo[ss]){
			puts(a[i]);
			bo[ss]=1;
		}
	}
// never say goodbye
}