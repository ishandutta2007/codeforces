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

string str;
string str2;
int N;

int main(){
	cin>>str;
	str2 = str;
	N = str.size();
	for(int i=1; i<N; i++){
		for(int j=0; j<N; j++){
			str2[j] = str[(i+j)%N];
		}
		bool tf = false;
		for(int j=0; j<N; j++){
			if(str[j]!=str2[j])	tf = true;
		}
		if(!tf)	continue;
		for(int j=0; j*2<N; j++){
			if(str2[j]!=str2[N-j-1]){
				tf = false; break;
			}
		}
		if(tf){
			printf("1");
			return 0;
		}
	}
	bool tf = true;
	for(int i=0; i*2<N-1; i++){
		//cout<<i<<endl;
		if(str[i]!=str[0] || str[N-i-1]!=str[0]){
			tf = false;
		}
	}
	if(tf){
		cout<<"Impossible";
	}else{
		cout<<2;
	}

	return 0;
}