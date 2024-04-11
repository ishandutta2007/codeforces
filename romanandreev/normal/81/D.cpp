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
int n,m;
int ans[10000];
pi a[10000];
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d",&a[i].fs);
		a[i].sc=i+1;
	}
	sort(a,a+m);
	for (int i=0;i<n;i+=2){
		bool bol=false;
		for (int j=m-1;j>=0;j--){
			if (a[j].fs>0){
				ans[i]=a[j].sc;
				if (ans[i]==ans[(i+1)%n] || ans[i]==ans[(i-1+n)%n]){
					ans[i]=0;
					continue;
				}
				a[j].fs--;
				bol=true;
				break;
			}
		}
		if (!bol){
			printf("-1\n");
			return 0;
		}
	}
	for (int i=1;i<n;i+=2){
		bool bol=false;
		for (int j=m-1;j>=0;j--){
			if (a[j].fs>0){
				ans[i]=a[j].sc;
				if (ans[i]==ans[(i+1)%n] || ans[i]==ans[(i-1+n)%n]){
					ans[i]=0;
					continue;
				}
				a[j].fs--;
				bol=true;
				break;
			}
		}
		if (!bol){
			printf("-1\n");
			return 0;
		}
	}
	for (int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
    return 0;
}