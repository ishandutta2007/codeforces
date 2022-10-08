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
int n,a,b;
pi p[1000000];
int ans[1000000];
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    for (int i=0;i<n;i++){
    	scanf("%d",&p[i].fs);
    	p[i].fs*=(a-b);
    	p[i].sc=i;
    	ans[i]=1;
    }
    sort(p,p+n);
    for (int i=0;i<b;i++){
    	ans[p[n-1-i].sc]=2;
    }
    for (int i=0;i<n;i++)
    	printf("%d ",ans[i]);
    printf("\n");
    return 0;
}