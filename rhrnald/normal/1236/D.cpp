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
int n,m,k,x,y;
 
vector<int> X[N], Y[N];
 
int main(void){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<k; i++) {
		scanf("%d%d", &x, &y);
		X[x].push_back(y);
		Y[y].push_back(x);
	}
	for(int i=1; i<=n; i++) sort(all(X[i]));
	for(int i=1; i<=m; i++) sort(all(Y[i]));
	
	int a=1,b=m,c=n,d=1;
	int st=0;
	ll vst=0;
	while(a<=c && d<=b) {
	    //printf("%d %d %d %d %d\n", st, a, b, c, d);
		if(st==0) {
			int idx=lower_bound(all(X[a]), d)-X[a].begin();
			if(idx==sz(X[a]) || X[a][idx]>b) {
				vst+=b-d+1;
				a++;
				st=1;
				continue;
			}
			b=X[a][idx]-1;
			vst+=b-d+1;
			a++;
			st=1;
		} else if(st==1) {
			int idx=lower_bound(all(Y[b]), a)-Y[b].begin();
			if(idx==sz(Y[b]) || Y[b][idx]>c) {
				vst+=c-a+1;
				b--;
				st=2;
				continue;
			}
			c=Y[b][idx]-1;
			vst+=c-a+1;
			b--;
			st=2;
		} else if(st==2) {
			int idx=upper_bound(all(X[c]), b)-X[c].begin()-1;
			if(idx<0 || X[c][idx]<d) {
				vst+=b-d+1;
				c--;
				st=3;
				continue;
			}
 
			d=X[c][idx]+1;
			vst+=b-d+1;
			c--;
			st=3;
		} else if(st==3) {
			int idx=upper_bound(all(Y[d]), c)-Y[d].begin()-1;
			if(idx<0 || Y[d][idx]<a) {
				d++;
				st=0;
				vst+=c-a+1;
				continue;
			}
            
			a=Y[d][idx]+1;
			vst+=c-a+1;
			d++;
			st=0;
		}
	}
	if(vst+k==1ll*n*m) printf("Yes");
	else printf("No");
}