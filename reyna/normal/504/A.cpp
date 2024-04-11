//In the name of God
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int Maxn = (1 << 17);
int Que[Maxn];
int begin,end;
int deg[Maxn];
int s[Maxn];
pair<int,int> edge[Maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d%d",&deg[i],&s[i]);
		if(!(deg[i]-1))
			Que[end++] = i;
	}
	int cnt = 0;
	while(begin != end){
		int now = Que[begin++];
		if(deg[now] != 1)
			continue;
		if(--deg[s[now]] > -1)
			edge[cnt++] = make_pair(now,s[now]);
		if(!(deg[s[now]]-1))
			Que[end++] = s[now];
		s[s[now]] = (s[s[now]] ^ now);
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt;i++){
		printf("%d %d\n",edge[i].first,edge[i].second);
	}
	return 0;
}