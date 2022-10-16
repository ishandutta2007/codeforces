#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
string s;
int siz,x,y;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	rep(a,0,9){
		cout<<a<<a<<a<<a<<endl;
		cin>>x>>y;
		if(x || y)v.pb(a);
	}
	rep(a,0,3){
		rep(b,0,3){
			if(b==a)continue;
			rep(c,0,3){
				if(c==a || c==b)continue;
				rep(d,0,3){
					if(d==a || d==b || d==c)continue;
					cout<<v[a]<<v[b]<<v[c]<<v[d]<<endl;
					cin>>x>>y;
					if(x==4)return 0;
				}
			}
		}
	}
	return 0;
}