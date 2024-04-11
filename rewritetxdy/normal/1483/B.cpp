#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int n,tt,cnt,c[N],ans[N];
set<int>s,t;

inline int gcd(int x,int y){
	return !y ? x : gcd(y,x%y);
}

int main()
{
	scanf("%d",&tt);
	while(tt--){
		cnt = 0;
		s.clear(); t.clear();
		scanf("%d",&n);
		for(int i=1;i <= n;i++){
			scanf("%d",&c[i]);
			s.insert(i);
			if(i > 1 && gcd(c[i],c[i-1]) == 1)
				t.insert(i);
		}
		if(gcd(c[1],c[n]) == 1) t.insert(1); 
		int x = 2;
		while(1){
			auto it = t.lower_bound(x);
			if(it == t.end()){
				x = 1;
				it = t.lower_bound(x);
				if(it == t.end()) break;
			}
//			cout<<*it<<endl;
			auto si = s.find(*it),l = s.end(),r = s.end();
			if(si == s.begin()) l = s.end() , --l;
			else l = --si , si++;
			r = ++si , si--;
			if(r == s.end()) r = s.begin();
//			cout<<*l<<' '<<*r<<endl;
			ans[++cnt] = *it; s.erase(si); t.erase(it);
			if(s.empty()) break;
			if(gcd(c[*l],c[*r]) == 1)
				t.insert(*r);
			else t.erase(*r);
			x = (*r)+1;
		}
		printf("%d ",cnt);
		for(int i=1;i <= cnt;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}