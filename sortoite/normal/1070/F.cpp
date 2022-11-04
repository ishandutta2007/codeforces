#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

vector<INT> vec_a, vec_b, vec_c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	int S=0, A=0, B=0, C=0;
	INT ans=0, sum;
	while(n--) {
		int a, b, x; scanf("%1d%1d %d", &a, &b, &x);
		if(a && b) S++, ans+=x;
		else if(a) A++, vec_a.pb(x);
		else if(b) B++, vec_b.pb(x);
		else C++, vec_c.pb(x);;
	}
	sum=ans;
	
	sort(vec_a.begin(), vec_a.end(), [](int u, int v) {return u>v;});
	sort(vec_b.begin(), vec_b.end(), [](int u, int v) {return u>v;});
	sort(vec_c.begin(), vec_c.end(), [](int u, int v) {return u>v;});
	
	for(int i=1; i<vec_a.size(); i++) vec_a[i]+=vec_a[i-1];
	for(int i=1; i<vec_b.size(); i++) vec_b[i]+=vec_b[i-1];
	for(int i=1; i<vec_c.size(); i++) vec_c[i]+=vec_c[i-1];
	
	for(int k=0; k<=S; k++) {
		INT c_sum=0;
		if(vec_a.size()+k-1<vec_b.size() && vec_a.size()+k-1>=0) {
			if(!vec_a.empty()) smax(c_sum, vec_a.back() + vec_b[vec_a.size()+k-1]);
			else smax(c_sum, vec_b[vec_a.size()+k-1]);
		}
		if(vec_a.size()-k-1<vec_b.size() && vec_a.size()-k-1>=0) {
			if(!vec_a.empty()) smax(c_sum, vec_a.back() + vec_b[vec_a.size()-k-1]);
		}
		if(vec_b.size()+k-1<vec_a.size() && vec_b.size()+k-1>=0) {
			if(!vec_b.empty()) smax(c_sum, vec_b.back() + vec_a[vec_b.size()+k-1]);
			else smax(c_sum, vec_a[vec_b.size()+k-1]);
		}
		if(vec_b.size()-k-1<vec_a.size() && vec_b.size()-k-1>=0) {
			if(!vec_b.empty()) smax(c_sum, vec_b.back() + vec_a[vec_b.size()-k-1]);
		}
		
		if(min(C, S-k)-1>=0) smax(ans, c_sum+sum+vec_c[min(C, S-k)-1]);
		else smax(ans, c_sum+sum);
	}
	cout<<ans<<endl;
}