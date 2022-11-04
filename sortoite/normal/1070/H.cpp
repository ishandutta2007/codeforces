#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int n, m;
	cin >> n;
	
	map <string, int> cnt;
	map <string, string> com;
	
	char s[11];
	for(int i=0; i<n; i++){
		map <string, int> vst;
		scanf("%s", s);
		string str=string(s);
		for(int i=0; i<str.size(); i++){
			for(int j=1; i+j<=str.size(); j++){
				string ss=str.substr(i, j);
				if(vst.count(ss)) continue;
				vst[ss]=1;
				if(!cnt[ss]++) com[ss]=str;
			}
		}
	}
	
	cin >> m;
	while(m--){
		scanf("%s", s);
		if(cnt.count(s)){
			printf("%d %s\n", cnt[s], com[s].c_str());
		}
		else printf("0 -\n");
	}
	
	return 0;
}