#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
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
int a[1000000];
char ff[10000100];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,x;
	scanf("%d%d",&n,&x);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	x=min(x,10000000);
	int ans=0;
	if (x==2) {
		printf("0\n");
		return 0;
	}
	for (int i=0;i<n;i++) {
		if (a[i]==1){
			printf("1\n");
			return 0;
		}
		if (i>0 && a[i]==a[i-1]) continue;
		bool bol=false;
		for (int j=a[i];j<x;j+=a[i]){
			if (ff[j]==0){
				ff[j]=1;
				bol=true;
			}
		}
		if (bol) ans++;
	}
	for (int i=2;i<x;i++) if (ff[i]==0){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<ans<<endl;
    return 0;
}