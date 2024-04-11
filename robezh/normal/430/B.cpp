#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> P;

int n,k,x;
deque<P> que;
deque<P> tmp;
int color[105];


void pushIntoTmp(int color){
	if(tmp.empty() || tmp.front().first != color) tmp.push_front(P(color, 1));
	else tmp.front().second ++;
}

void pushIntoQue(int color){
	if(que.empty() || que.front().first != color) que.push_front(P(color, 1));
	else que.front().second ++;
}

void get_tmp(int t){
	tmp.clear();
	for(int i = 0; i < n; i++){
		if(t == i) pushIntoTmp(x);
		pushIntoTmp(color[i]);
	}
	if(t == n) pushIntoTmp(x);
}

int get_ans(int t){
	get_tmp(t);
	que.clear();
	while(tmp.size()){
		P p = tmp.front();
		tmp.pop_front();
		if(que.empty() || (que.front().first != p.first && p.second < 3 )){
			que.push_front(p); continue;
		}
		    
		if(que.front().first == p.first){
			if(que.front().second + p.second < 3) { que.front().second += p.second; }
			else que.pop_front();
		}
	}
	
	int exi = 0;
	while(que.size()){
		exi += que.front().second;
		que.pop_front();
	}
	return n - exi;
}

int main(){
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &color[i]);
	}
	get_tmp(0);
	while(tmp.size()){
		P p = tmp.front();
		tmp.pop_front();
		//cout << p.first <<" " << p.second << endl;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, get_ans(i));
	}
	cout << ans;
}