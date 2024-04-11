#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
map<string,bool> hav;
int n;
char a[N][13];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%s",a[i]+1);
	per(i,n,1){
		if(hav[a[i]+1])continue;
		printf("%s\n",a[i]+1);
		hav[a[i]+1]=1;
	}
	return 0;
}