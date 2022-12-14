#include <bits/stdc++.h>

using namespace std;

int d[4][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

struct inq {
	int x , y;
	inq (int x = 0 , int y = 0) : x(x) , y(y) {} 
};

struct seq {
	int siz , id;
	bool operator < (const seq &t) const {
		return siz > t.siz;
	}
}b[6000];

char s[700][700];

int vis[700][700] , F[6000] , id , n , m , tot , k;

void bfs(int sx , int sy) {
	id ++;
	queue < inq > Q;
	Q.push(inq(sx , sy));
	bool flag = 0;
	int siz = 0;
	if (sx == 1 || sy == 1 || sx == n || sy == m) flag = 1;
	while (!Q.empty()) {
		inq now = Q.front();
		Q.pop();
		vis[now.x][now.y] = id;
		siz ++;
//		printf("%d\n" , siz);
	//	printf("%d %d\n" , now.x , now.y);
		for (int i = 0 ; i < 4 ; i ++) {
			int xx = now.x + d[i][0] , yy = now.y + d[i][1];
			if (xx < 1 || yy < 1 || xx > n || yy > m || s[xx][yy] == '*' || vis[xx][yy]) continue;
			vis[xx][yy] = id;
			Q.push(inq(xx , yy));
			if (xx == 1 || yy == 1 || xx == n || yy == m) flag = 1;
		} 
	}
	if (flag == 0) {
		b[++ tot].id = id;
		b[tot].siz = siz;		
	}
}

int main() {
//	freopen("a.in" , "r" , stdin);
	n = read() , m = read() , k = read();
	for (int i = 1 ; i <= n ; i ++) scanf("%s" , s[i] + 1);
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) {
			if (s[i][j] == '*' || vis[i][j]) continue;
			bfs(i , j);
		}
	}
	sort(b + 1 , b + tot + 1);
	int tmp = 0;
	for (int i = k + 1 ; i <= tot ; i ++) F[b[i].id] = 1;
	for (int i = 1 ; i <= k ; i ++) F[b[i].id] = 2;
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m ; j ++) 
			if (F[vis[i][j]] == 1) tmp ++;
	printf("%d\n" , tmp);
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) {
			if (s[i][j] == '*') printf("%c" , '*');
			else {
				if (F[vis[i][j]] == 1)  printf("%c" , '*');
				else if (F[vis[i][j]] == 2) printf("%c" , '.');
				else printf("%c" , '.');
			}
		}
		if (i != n) puts("");
	}
	return 0;
}