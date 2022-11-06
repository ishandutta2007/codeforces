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

const int N = 1001;
int n,m;
int x[N];
bool vst[N];
int a,b;

vector<int> v[2];
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", x+i);
	}
	bool flag=0;
	for(int i=1; i<=n; i++) if(x[i]) {flag=true; break;}
	if(!flag) {
		if(n==1) printf("0");
		else printf("1");
		return 0;
	}

	for(int i=1; i<=n; i++) vst[x[i]]=true;
	for(int i=1; i<=n; i++) {
		if(!vst[i]) {
			if(i&1) b++;
			else a++;
		}
	}

	int prv=-1;
	int c=0;
	int l=-1, o=-1;
	int p=-1, q=-1;
	for(int i=1; i<n; i++) {
		if(x[i] && x[i+1]) if((x[i]-x[i+1])&1) c++;
	}
	for(int i=1; i<=n;) {
		if(x[i]) prv=x[i], i++;
		else {
			int num=0;
			while(i<=n && !x[i]) num++, i++;
			int nxt=x[i]; if(i>n) nxt=-1;
			if(prv==-1) {
				l=num;
				o=nxt&1;
			} else if(nxt==-1) {
				p=num;
				q=prv&1;
			} else {
				if((nxt&1)==(prv&1)) v[nxt&1].push_back(num);
				else c++;
			}
		}
	}
	sort(all(v[0]));
	sort(all(v[1]));
	for(int e : v[0]) {
		if(a>=e) a-=e;
		else c+=2;
	}
	for(int e : v[1]) {
		if(b>=e) b-=e;
		else c+=2;
	}
	if(o==0) {
		if(a<l) c++;
		else a-=l;
	}
	if(o==1) {
		if(b<l) c++;
		else b-=l;
	}
	if(q==0) {
		if(a<p) c++;
	}
	if(q==1) {
		if(b<p) c++;
	}
	printf("%d", c);
}