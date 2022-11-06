#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
 
const int N = 1000001;
int n,m,k,K;
int x[N];
vector<int> v;
int cnt[N];
int psum[N];
int ssum[N];
int num;
 
int main(void){
	scanf("%d%d", &n, &m);
	k=m*8/n;
 
	for(int i=0; i<n; i++) scanf("%d", x+i);
	sort(x, x+n);
	for(int i=0; i<n; i++) {
		if(i==0 || x[i]!=x[i-1]) {
			num++;
			cnt[num]=1;
		} else 	cnt[num]++;
	}
	if(!((num-1)>>k) || k>20) {printf("0"); return 0;}
	K=(1<<k);
	ssum[num+1]=0;
	for(int i=num; i>=1; i--) ssum[i]=ssum[i+1]+cnt[i];
	psum[0]=0;
	for(int i=1; i<=num; i++) psum[i]=psum[i-1]+cnt[i];
 
	int ans=INF;
	for(int i=1; i<=num-K+1; i++) {
		ans=min(psum[i-1]+ssum[K+i], ans);
	}
	printf("%d", ans);
}