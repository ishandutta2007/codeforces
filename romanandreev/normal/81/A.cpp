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
char s[1000000];
char a[1000000];

int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	scanf("%s",s);
	int tk=0;
	for (int i=0;s[i];i++){
		if (tk>0 && s[i]==a[tk-1]){
			tk--;
		} else {
			a[tk++]=s[i];
		}
	}
	for (int i=0;i<tk;i++) printf("%c",a[i]);
	printf("\n");
    return 0;
}