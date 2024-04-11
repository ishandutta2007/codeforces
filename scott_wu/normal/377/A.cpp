#include <iostream> //scott http://codeforces.com/contest/377/problem/A
#include <cstdio>
#include<cstring>
using namespace std;
const int MAXN = 510;

int N, M, K;
int S = 0;
int good[MAXN][MAXN]; // 0 for bad square, 1 for empty square, 2 for already marked square

int xc[4] = {0, 0, -1, 1};
int yc[4] = {-1, 1, 0, 0};

void run (int x, int y)
{
	if (good[x][y] != 1) return;
	if (S == K) return;
	S--;
	good[x][y] = 2;
	
	for (int i = 0; i < 4; i++)
		run (x + xc[i], y + yc[i]);
}




char Ch[3] = {'#','X','.'};
int main(){
     char ch ;
     scanf("%d%d%d",&N,&M,&K);
     memset(good, 0, sizeof(good));
     S = 0; // S is # empty squares right
     for (int i = 1; i <= N; i ++){ // 1..n so the border is all bad squares
        scanf("\n"); 
        for (int j = 1; j <= M; j ++){
            scanf("%c",&ch);
            good[i][j] = (ch == '.');
            S += good[i][j];
        }
    }
    for (int i = 1; i <= N; i ++)
       for (int j = 1; j <= M; j ++)
           if (good[i][j] == 1 && S > K) run(i,j);
    for (int i = 1; i <= N; i ++){
        for (int j = 1; j <= M; j ++)
            printf("%c",Ch[good[i][j]]);
        printf("\n");
     }
     return 0;
}