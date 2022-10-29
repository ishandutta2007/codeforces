#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 100500

using namespace std;

int n, k;
string l_wall, r_wall;
bool used[maxn][2];
int q[maxn * 2][2];
int time_go[maxn][2];
int beg = 1, en = 0;
bool dang[maxn][2];
bool res = false;

int add(const int &x, const int &y, const int &tt){
	//cerr << "1:: " <<  x << ' ' << y << ' ' << dang[x][y] << '\n';
	++en;
	used[x][y] = true;
	q[en][0] = x;
	q[en][1] = y;
	time_go[x][y] = tt;
	return 0;
}

int BFS(const int &x, const int &y){
	//cerr << x << ' ' << y << ' ' << dang[x][y] << '\n'; 
	if(x > 1 && !used[x - 1][y] && !dang[x - 1][y] && time_go[x][y] + 1 < x - 1)add(x - 1, y, time_go[x][y] + 1);
	if(x > n - 1)res = true;
	if(x < n && !used[x + 1][y] && !dang[x + 1][y])add(x + 1, y, time_go[x][y] + 1);
	if(x > n - k)res = true;
	if(x <= n - k && !used[x + k][1 - y] && !dang[x + k][1 - y])add(x + k, 1 - y, time_go[x][y] + 1);
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin.ignore(1e+4, '\n');
	getline(cin, l_wall, '\n');
	getline(cin, r_wall, '\n');
	memset(used, 0, sizeof(used));
	memset(dang, 0, sizeof(dang));
	for(int i = 0; i < n; ++i)dang[i + 1][0] = (l_wall[i] == 'X');
	for(int i = 0; i < n; ++i)dang[i + 1][1] = (r_wall[i] == 'X');
	add(1, 0, 0);
	while(!res && beg <= en){
		BFS(q[beg][0], q[beg][1]);
		++beg;
	}

	//for(int i = 1; i <= n; ++i)cerr << time_go[i][0] << ' ' << dang[i][0] << '\n';

	if(res)cout << "YES\n";
	else cout << "NO\n";

	return 0;
}