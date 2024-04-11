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
int n,m;
string s;
int ans[N];
int c[N];
vector<int> v;
void proc() {
	scanf("%d", &n);
	cin >> s;
	for(int i=0; i<n; i++) c[i]=s[i]-'0';

	for(int h=0; h<10; h++) {
		int c1=-1, c2=-1;
		bool flag=false;
		int l=n,r=-1;
		for(int i=0; i<n; i++) {
			if(c[i]>h) {
				if(c2>c[i]) {flag=true; break;}
				c2=c[i];
				l=min(l,i);
			} else if(c[i]<h) {
				if(c1>c[i]) {flag=true; break;}
				c1=c[i];
				r=i;
			}
		}
		if(!flag) {
			bool f=false;
			for(int i=l+1; i<r; i++) if(c[i]==h) {f=true; break;}
			if(f) continue;


			for(int i=0; i<n; i++) {
				if(c[i]>h) printf("2");
				else if(c[i]<h) printf("1");
				else {
					if(i<l) printf("2");
					else printf("1");
				}
			}
			printf("\n");
			return;
		}
	}
	printf("-\n");
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}