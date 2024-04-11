#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

struct tv{
	int t;
	map <string, int> go;
};

int ans1, ans2;
int f[10100], p[10100];
string lst[200];
tv ver[10100];

void dfs(int a){
	for(map <string, int> :: iterator it = ver[a].go.begin(); it != ver[a].go.end(); it++){
		dfs(it->second);
		p[a] += p[it->second];
		f[a] += f[it->second];
	}
	if(ver[a].t == 1){
		ans1 = max(ans1, p[a]);
		ans2 = max(ans2, f[a]);
	}
	if(ver[a].t == 1){
		p[a]++;
	}
	if(ver[a].t == 2){
		f[a]++;
	}
}

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	string s;
	int n = 0;
	while(cin >> s){
		int sz = 0;
		string cur = "";
		for(int i = 0; i < (int)s.length(); i++){
			if(s[i] == '\\'){
				lst[sz++] = cur;
				cur = "";
			}
			else{
				cur += s[i];
			}
		}
		int v = 0;
		lst[1] = lst[0] + '\\' + lst[1];
		for(int i = 1; i < sz; i++){
			if(ver[v].go.find(lst[i]) == ver[v].go.end()){
				ver[++n].t = 1;
				ver[v].go[lst[i]] = n;
			}
			v = ver[v].go[lst[i]];
		}
		ver[++n].t = 2;
		ver[v].go[cur] = n;
	}
	ans1 = ans2 = 0;
	dfs(0);
	printf("%d %d\n", ans1, ans2);
	return 0;
}