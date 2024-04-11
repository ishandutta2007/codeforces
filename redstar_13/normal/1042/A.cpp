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

const int NN = 1011;
int n,m;
int mn, mx;
int a[NN];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	mx = a[n-1] + m;
	
	int tot = 0;
	for (int i=0; i<n-1; i++) tot+=a[n-1] - a[i];
	mn = a[n-1];
	if (m>tot) {
		mn+=(m-tot)/n;
		if ((m-tot)%n) mn++;
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}