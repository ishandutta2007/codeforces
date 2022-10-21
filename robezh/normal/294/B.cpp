#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

int n;
int book[3][105];
int comb[3][105][2];
int t1n = 0, t2n = 0;

int main() {
    int n;
    int type, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &type, &tmp);
        if(type == 1) book[1][t1n++] = tmp;
        else book[2][t2n++] = tmp;
    }
    sort(book[1], book[1] + t1n);
    sort(book[2], book[2] + t2n);
//    for(int i = 0; i < t1n; i++) cout << book[1][i] << endl;
//    for(int i = 0; i < t2n; i++) cout << book[2][i] << endl;
    
    comb[1][0][0] = 0;
    comb[1][0][1] = t1n;
    for(int i = 1; i <= t1n; i++) {
        comb[1][i][0] = comb[1][i-1][0] + book[1][i-1];
        comb[1][i][1] = comb[1][i-1][1] - 1;
    }

    comb[2][0][0] = 0;
    comb[2][0][1] = 2 * t2n;
    for(int i = 1; i <= t2n; i++) {
        comb[2][i][0] = comb[2][i-1][0] + book[2][i-1];
        comb[2][i][1] = comb[2][i-1][1] - 2;
    }
    
    int minWid = INF;
    for(int i = 0; i <= t1n; i++){
    	for(int j = 0; j <= t2n; j++){
    		if(comb[2][j][0] + comb[1][i][0] <= comb[2][j][1] + comb[1][i][1]){
    			minWid = min(minWid, comb[2][j][1] + comb[1][i][1]);
			}
		}
	}
	cout << minWid << endl;
}