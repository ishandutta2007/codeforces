#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

#define NN 100100
int a[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	
	INT sum=0;
	for(int i=0; i<n; i++) scanf("%d", a+i), sum+=a[i];
	
	if(sum%k) return puts("No"), 0;
	sum/=k;
	
	VI ans;
	for(int i=0, j=0; i<n; i=j){
		INT s=0;
		while(j<n && s<sum) s+=a[j++];
		if(s>sum) return puts("No"), 0;
		ans.pb(j-i);
	}
	
	puts("Yes");
	for(int x : ans) printf("%d ", x); puts("");
	
	return 0;
}