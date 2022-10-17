#include <iostream>
using namespace std;

char avail[16];
int M;
bool can[1005][10][10];

void trace(int m, int ld, int nw = -1){
    int lw = -1;
    for(int l=1; l<=10; l++){
        if(l == nw) continue;
        if(can[m][l][ld]){
            lw = l;
            if(m > 1) trace(m-1, lw - ld, lw);
            break;
        }
    }
    
    cout << lw << " ";
}

int main(){
    for(int i=1; i<=10; i++)
        cin >> avail[i];
    cin >> M;

    for(int i=1; i<=10; i++)
        if(avail[i] == '1')
            can[1][i][i] = true;

    for(int m=2; m<=M; m++)
        for(int l=1; l<=10; l++)
            if(avail[l] == '0') continue;
            else for(int d=1; d<=10; d++){
                if(d >= l) continue;
                int o = l - d;
                bool could = false;
                for(int p=1; p<=10; p++)
                    if(p == l) continue;
                    else could |= can[m-1][p][o];
                can[m][l][d] = could; 
            }

    int ld = -1;
    for(int l=1; l<=10; l++)
        for(int d=1; d<=10; d++)
            if(can[M][l][d]){
                ld = d;
                break;
            }
    
    if(ld != -1){
        cout << "YES\n";
        trace(M, ld);
        cout << "\n";
    }
    else cout << "NO\n";
    cout.flush();
    return 0;
}