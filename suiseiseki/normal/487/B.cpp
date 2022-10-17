#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
int a[Maxn+5],ans[Maxn+5],Left[Maxn+5];
multiset<int> p;
int main() {
	int n,l,s;
	cin>>n>>s>>l;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	int now = 0;
	for(int i = 0; i < n; i++) {
		while(!p.empty()) {
			int Min = *p.begin(),Max = *(--p.end());
			if(Max - a[i] <= s && a[i] - Min <= s) break;
			p.erase(p.lower_bound(a[now]));
			now++;
		}
		Left[i] = now;
		p.insert(a[i]);
	}
	now = 0;
	p.clear();
	ans[0] = 0;
	for(int i = 1; i <= n; i++) {
		if(i >= l)
			p.insert(ans[i-l]);
		while(now <= i-l && now < Left[i-1]) {
			p.erase(p.lower_bound(ans[now]));
			now++;
		}
		if(p.empty())
			ans[i]=Maxn;
		else
			ans[i] = *p.begin() + 1;
	}
	if(ans[n] >= Maxn)
		cout<<-1<<endl;
	else
		cout<<ans[n]<<endl;
	return 0;
}