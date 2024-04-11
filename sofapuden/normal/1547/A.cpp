#include<bits/stdc++.h>
#define s second
#define f first

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		pair<int,int> a[3];
		for(auto &x : a)cin >> x.f >> x.s;
		int dis = abs(a[0].f-a[1].f)+abs(a[0].s-a[1].s);
		if(a[0].s == a[1].s){
			for(auto &x : a)swap(x.f,x.s);
		}
		if(a[0].f == a[1].f){
			if(a[2].s > min(a[1].s,a[0].s) && a[2].s < max(a[1].s,a[0].s) && a[2].f == a[1].f){
				cout << dis+2 << '\n';
			}
			else{
				cout << dis << '\n';
			}
		}else{
			cout << dis << '\n';
		}
	}
}