#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int n;
char s[1000000];
char ans[1000000];

void trr(int k,int c4,int c7,int fl){
	if (k==0){
		for (int i=0;i<n;i++)
			printf("%c",ans[i]);
		printf("\n");
		exit(0);
	}
	if (c4>0 && ((s[n-k]<='4') || fl)){
		ans[n-k]='4';
		trr(k-1,c4-1,c7,fl||(s[n-k]<'4'));
	}
	if (c7>0 && ((s[n-k]<='7') || fl)){
		ans[n-k]='7';
		trr(k-1,c4,c7-1,fl||(s[n-k]<'7'));
	}
}
void tryy(int l){
	if (l%2==1) return;
	if (l>n){
		for (int i=0;i<l/2;i++){
			printf("4");
		}
		for (int i=0;i<l/2;i++){
			printf("7");
		}
		printf("\n");
		exit(0);
	}
	trr(n,n/2,n/2,0);
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%s",s);
	n=strlen(s);
	tryy(n);
	tryy(n+1);
	tryy(n+2);
    return 0;
}