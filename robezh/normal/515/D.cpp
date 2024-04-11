#include<cstdio>
#include<iostream>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int options[2005][2005];
int dot_left = 0;
int n,m;
char c[2005][2005];


bool in_bound(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool valid(int i, int j) {
    return in_bound(i, j) && c[i][j] == '.';
}

int cnt_options(int i, int j) {
	if(options[i][j] < 0) return options[i][j];
    int res = 0;
    for(int k = 0; k < 4; k++) {
        if(valid(i+dx[k],j+dy[k])) res++;
    }
    return res;
}

void dfs(int i, int j);

void search(int i, int j) {
    for(int k = 0; k < 4; k++) {
    	int di = i+dx[k], dj = j+dy[k];
        if(valid(di,dj) && cnt_options(di,dj) == 1) {
            options[di][dj] --;
            dfs(di,dj);
        }
    }
}

void dfs(int i, int j) {
    if(valid(i+1, j)) {
        c[i][j] = '^';
        c[i+1][j] = 'v';
        search(i+1,j);
        return ;
    }
    if(valid(i-1, j)) {
        c[i][j] = 'v';
        c[i-1][j] = '^';
        search(i-1,j);
        return ;
    }
    if(valid(i, j+1)) {
        c[i][j] = '<';
        c[i][j+1] = '>';
        search(i,j+1);
        return ;
    }
	if(valid(i, j-1)) {
        c[i][j] = '>';
        c[i][j-1] = '<';
        search(i,j-1);
        return ;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == '.' && cnt_options(i,j) == 1) dfs(i, j);
        }
    }
    bool fulfilled = true;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(c[i][j] == '.') {
                return !printf("Not unique");
            }
    for(int i = 0; i < n; i++) printf("%s\n",c[i]);


}