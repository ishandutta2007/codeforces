#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}

int n,a[10005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				if(fabs(a[i]-a[j])<=2&&a[i]!=a[j]&&fabs(a[i]-a[k])<=2&&a[i]!=a[k]&&fabs(a[j]-a[k])<=2&&a[j]!=a[k]){puts("YES");return 0;}
			}
	puts("NO");
	return 0;
}