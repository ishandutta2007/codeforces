#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k;
char ans[3000333];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	if (k==1&&n>1){
		puts("-1");
		return 0;
	}
	if (n<k){
		puts("-1");
		return 0;
	}
	for (int i=0;i<n-k;i++)ans[i]=('a'+(i%2));
	for (int i=0;i<k;i++)ans[n-k+i]=i+'a';
	for (int i=n-2;i>0;i--)if (ans[i]==ans[i-1]){
		swap(ans[i],ans[i+1]);
		break;
	}
	for (int i=n-2;i>=0;i--)if (ans[i]==ans[i+1]){
		puts("-1");
		return 0;
	}
	puts(ans);
	return 0;
}