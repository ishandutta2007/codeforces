#include <cstdio>
#include <climits>
using namespace std;

int na, nb, ma, mb, ansx, ansy, res;
int ta[101][101], tb[101][101];

int main(){
    scanf("%d %d", &na, &ma);
    ansx = ansy = res = -INT_MAX;
    for(int i = 0; i < na; i++){
	getchar();
	for(int j = 0; j < ma; j++){
	    char c;
	    scanf("%c", &c);
	    if(c == '0') ta[i][j] = 0;
	    else ta[i][j] = 1;
	}
    }
    scanf("%d %d", &nb, &mb);
    for(int i = 0; i < nb; i++){
	getchar();
	for(int j = 0; j < mb; j++){
	    char c;
	    scanf("%c", &c);
	    if(c == '0') tb[i + na][j + ma] = 0;
	    else tb[i + na][j + ma] = 1;
	}
    }
    for(int i = 0; i < na + nb; i++){
	for(int j = 0; j < ma + mb; j++){
	    int tmp = 0;
	    for(int p = 0; p < na; p++){
		for(int q = 0; q < ma; q++){
		    if(ta[p][q] && tb[i+p][j+q]) tmp++;
		}
	    }
	    if(tmp > res){
		ansx = i - na;
		ansy = j - ma;
		res = tmp;
	    }
	}
    }
    printf("%d %d\n", ansx, ansy);
    return 0;
}