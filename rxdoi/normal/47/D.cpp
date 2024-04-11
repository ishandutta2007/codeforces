#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define rep(x, a, b) for(int x=a; x<=b; x++)
set<long long> all, t;
set<long long>::iterator it;
int n, m, v;
long long a;
char s[100];
vector<long long> era;
void dfs(int pos, int get, long long val){
	if(get>v) return;
	if(pos==n)
	{
		if(get==v) t.insert(val);
		return;
	}
	dfs(pos+1, get+1, val+((a>>pos&1)<<pos));
	dfs(pos+1, get, val+(((a>>pos&1)^1)<<pos));
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		a=0;
		scanf("%s%d", s+1, &v);
		rep(i, 1, n) a=(a<<1)+s[i]-'0';
		t.clear();
		dfs(0, 0, 0);
		if(i==1) all=t;
		else{
			era.clear();
			for(it=all.begin(); it!=all.end(); it++)
				if(t.find(*it)==t.end()) era.pb(*it);
			rep(i, 0, (int)era.size()-1) all.erase(era[i]);
		}
	}
	printf("%d\n", (int)all.size());
}