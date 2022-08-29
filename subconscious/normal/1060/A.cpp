#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp pake_pair
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucksm
#define y1 fucklzw
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
int a[N],n;
char s[N];
int main(){
	scanf("%d",&n); 
	scanf("%s",s+1);
	rep(i,n)++a[s[i]-'0'];
	printf("%d\n",min(n/11,a[8]));
	return 0;
}