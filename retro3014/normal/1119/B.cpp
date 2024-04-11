#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, H;
vector<int> arr;
vector<int> v;

bool chk(int x){
	v.clear();
	for(int i=0; i<x; i++){
		v.pb(arr[i]);
	}
	sort(v.begin(), v.end());
	int h = H;
	while(!v.empty()){
		if(h<v.back()){
			return false;
		}
		h-=v.back();
		v.pop_back();
		if(!v.empty())	v.pop_back();
	}
	return true;
}

int main(){
	scanf("%d %d", &N, &H);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x); arr.pb(x);
	}
	int s = 1, e = N, m;
	while(s<e){
		m = (s+e)/2+1;
		if(chk(m))	s = m;
		else e = m-1;
	}
	cout<<s<<endl;
	return 0;
}