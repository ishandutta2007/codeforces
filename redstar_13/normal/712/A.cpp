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

const int NN = 100011;
int a[NN], b[NN];
int n;

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	for (int i=0; i<n-1; i++) b[i] = a[i] + a[i+1];
	b[n-1] = a[n-1];
	for (int i=0; i<n; i++) cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}