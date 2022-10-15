#include <iostream>
#define Maxn 710
#define M(x) ((x) % 1000000007)

using namespace std;

int n , tmp , ans , dep[Maxn];
long long f[3][3][Maxn][Maxn];
string s;

void Dfs(int d , int pl , int pr){
	if(pl + 1 == pr){
		f[1][0][pl][pr] = f[0][1][pl][pr] = f[2][0][pl][pr] = f[0][2][pl][pr] = 1;
		return;
	}
	int l = -1;
	bool fst = true;
	for(int r = pl + 1 ; r < pr ; r++)
		if(dep[r] == d){
			if(l == -1)
				l = r;
			else{
				Dfs(d + 1 , l , r);
				if(!fst)
					for(int i = 0 ; i <= 2 ; i++)
						for(int j = 0 ; j <= 2 ; j++)
							for(int x = 0 ; x <= 2 ; x++)
								if(j != x || j + x == 0)
									for(int y = 0 ; y <= 2 ; y++)
										f[i][y][pl + 1][r] = M(f[i][y][pl + 1][r] + f[i][j][pl + 1][l - 1] * f[x][y][l][r]);
				l = -1;
				fst = false;
			}
		}
	for(int i = 0 ; i <= 2 ; i++)
		if(i != 1)
			for(int j = 0 ; j <= 2 ; j++)
				f[1][0][pl][pr] = M(f[1][0][pl][pr] + f[i][j][pl + 1][pr - 1]);
	for(int i = 0 ; i <= 1 ; i++)
		for(int j = 0 ; j <= 2 ; j++)
			f[2][0][pl][pr] = M(f[2][0][pl][pr] + f[i][j][pl + 1][pr - 1]);
	for(int i = 0 ; i <= 2 ; i++)
		for(int j = 0 ; j <= 2 ; j++)
			if(j != 1)
				f[0][1][pl][pr] = M(f[0][1][pl][pr] + f[i][j][pl + 1][pr - 1]);
	for(int i = 0 ; i <= 2 ; i++)
		for(int j = 0 ; j <= 1 ; j++)
			f[0][2][pl][pr] = M(f[0][2][pl][pr] + f[i][j][pl + 1][pr - 1]);
}

int main(){
	cin >> s;
	s = " (" + s + ")";
	n = s.size() - 1;
	tmp = 1;
	for(int i = 1 ; i <= n ; i++)
		if(s[i] == '(')
			dep[i] = tmp++;
		else
			dep[i] = --tmp;
	Dfs(2 , 1 , n);
	for(int i = 0 ; i <= 2 ; i++)
		for(int j = 0 ; j <= 2 ; j++)
			ans = M(ans + f[i][j][2][n - 1]);
	cout << ans << endl;
	return 0;
}

// By Sooke.
// CF149D Coloring Brackets.