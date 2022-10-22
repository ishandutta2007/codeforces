#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005],f[1005][1005][2],num[1005][1005][2];
vector<char> path;
void print(int x, int y,int flag,char dir) {
	if(x == 1 && y == 1){
		path.push_back(dir);
		return ;
	}	
	else if(x == 1) print(x,y - 1,flag,'R');
	else if(y == 1) print(x - 1,y,flag,'D');
	else {
		if(f[x][y][flag] == f[x - 1][y][flag] + num[x][y][flag]) print(x - 1,y,flag,'D');
		else print(x,y - 1,flag,'R');
	}
	path.push_back(dir);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	int flag = 0,x,y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin>>a[i][j];
			if(a[i][j] == 0) {
				flag = 1;
				x = i,y = j;
				num[i][j][0] = 1;
				num[i][j][1] = 1;
				continue;
			}
			int cnt = 0;
			while(a[i][j] % 2 == 0) a[i][j] /= 2,cnt++;
			num[i][j][0] = cnt;
			cnt = 0;
			while(a[i][j] % 5 == 0) a[i][j] /= 5,cnt++;
			num[i][j][1] = cnt;
		}
	}
	memset(f,0x3f,sizeof f);
	f[1][1][0] = num[1][1][0];
	f[1][1][1] = num[1][1][1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == 1 && j == 1) continue;
			if(a[i][j] == 0) f[i][j][1] = f[i][j][0] = 0;
			else {
				if(i - 1) {
					f[i][j][0] = min(f[i - 1][j][0],f[i][j][0]);
					f[i][j][1] = min(f[i - 1][j][1],f[i][j][1]);	
				} 
				if(j - 1) {
					f[i][j][0] = min(f[i][j][0],f[i][j - 1][0]);
					f[i][j][1] = min(f[i][j][1],f[i][j - 1][1]);
				} 
				f[i][j][0] += num[i][j][0];
				f[i][j][1] += num[i][j][1];
			} 
		}
	}
	int ans = min(f[n][n][0],f[n][n][1]);
	if(flag && ans >= 1) {
		cout<<1<<endl;
		for(int i = 1; i < x; i++) cout<<'D';
		for(int i = 1; i < y; i++) cout<<'R';
		for(int i = x; i < n; i++) cout<<'D';
		for(int i = y; i < n; i++) cout<<'R';
		return 0;
	}
	if(f[n][n][0] < f[n][n][1]) print(n,n,0,'.');
	else print(n,n,1,'.');
	path.pop_back();
	cout<<ans<<endl;
	for(auto &x :path) cout<<x;
	return 0;
}
//test