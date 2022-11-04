#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i ++)
#define mx 100010
#define LL long long
using namespace std;

int a[mx];
vector<pair<int, int>>res;
int num[5];
int f[mx];
set<int>s;
int row[mx], col[mx];
vector<int>one;
queue<int>q1, q2;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	rep(i, 0, n) scanf("%d", &a[i]);
	rep(i, 0, n) num[a[i]] ++;
	if(num[0] == n) return puts("0"), 0;
	int pre, pos;
	for(int i = n - 1; i >= 0; i --){
		if(a[i] == 0) continue;
		if(a[i]) {
			pre = a[i];
			pos = i;
			break;
		}
	}
	if(pre != 1) return puts("-1"), 0;
	int h = 0, fro;
	q1.push(pos);
	for(int i = pos - 1; i >= 0; i --){
		if(a[i] == 0) continue;
		if(a[i] == 1) q1.push(i);
		else if(a[i] == 2){
			if(q1.empty()) return puts("-1"), 0;
			fro = q1.front();
			q1.pop();
			res.push_back({i, h});
			res.push_back({fro, h});
			q2.push(i);
			h ++;
		}
		else if(a[i] == 3){
			if(q2.empty() && q1.empty()) return puts("-1"), 0;
			if(!q2.empty()) {
				fro = q2.front();
				q2.pop();
				res.push_back({i, h});
				res.push_back({fro, h});
				q2.push(i);
				h ++;
			}
			else{
				fro = q1.front();
				q1.pop();
				res.push_back({fro, h});
				h ++;
				res.push_back({i, h});
				res.push_back({fro, h});
				q2.push(i);
				h ++;
			}
		}
	}
//	h ++;
	while(!q1.empty()){
		fro = q1.front();
		q1.pop();
		res.push_back({fro, h ++});
	}
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i ++){
		printf("%d %d\n", n - res[i].second, res[i].first + 1);
	}
}