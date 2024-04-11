#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define sq(x) x*x
#define inf 0x3f3f3f3f

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

const int NN = 1011;
double a,b;
double x,y,v;
int n;	
double mn = inf;

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>a>>b>>n;
	for (int i=0; i<n; i++) {
		scanf("%lf%lf%lf", &x,&y,&v);
		smin(mn,hypot(x-a,y-b)/(double)v);
	}
	printf("%.8lf\n", mn);
	return 0;
}