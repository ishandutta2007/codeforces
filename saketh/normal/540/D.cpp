#include <iostream>
using namespace std;

const int MAXN = 105;

int R, S, P;
double win[MAXN][MAXN][MAXN][3];

int main(){
    for(int i=1; i<=100; i++){
        win[i][0][0][0] = 1;
        win[0][i][0][1] = 1;
        win[0][0][i][2] = 1;
    }

    for(int tot=2; tot<=300; tot++)
        for(int a=0; a<=min(tot, 100); a++)
            for(int b=0; b<=min(tot-a, 100); b++){
                    int c = tot-a-b;
                    if(c>100) continue;
                    
                    int nz = int(a>0) + int(b>0) + int(c>0);
                    if(nz < 2) continue;

                    int wr = c * a;
                    int ws = a * b;
                    int wp = b * c;
                    int sm = wr + ws + wp;

                    for(int j=0; j<3; j++){
                        if(a>0) win[a][b][c][j] += wr/double(sm) * win[a-1][b][c][j];
                        if(b>0) win[a][b][c][j] += ws/double(sm) * win[a][b-1][c][j];
                        if(c>0) win[a][b][c][j] += wp/double(sm) * win[a][b][c-1][j];
                    }
                }

    cin >> R >> S >> P;
    cout.precision(20);
    for(int i=0; i<3; i++)
        cout << win[R][S][P][i] << " ";
    cout << endl;
}