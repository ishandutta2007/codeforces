#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

const int NN = 100111;
int n;
int a,b;
typedef pair<pii,int>pi3;
pi3 p[NN];

bool cmp( pi3 u,  pi3 v) {
	if (u.x.x == v.x.x) return u.x.y>v.x.y;
	return u.x<v.x;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	for (int i=0; i<n; i++) {
		scanf("%d%d",&a,&b);
		p[i] = make_pair(make_pair(a,b),i+1);
	}
	sort(p,p+n,cmp);
	for(int i=1; i<n; i++) 
		if (p[0].x.x>p[i].x.x) {
			puts("-1"); return 0;
		}
	for (int i=1; i<n; i++)
		if (p[0].x.y<p[i].x.y) {
			puts("-1"); return 0;
		}
	cout<<p[0].y<<endl;
	return 0;
}