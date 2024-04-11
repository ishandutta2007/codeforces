#include <iostream>
using namespace std;

int N;
long long grid[2048][2048];
long long diag1[4096], diag2[4096];

int main(){
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
                cin >> grid[i][j];
                diag1[i+j] += grid[i][j];
                diag2[(N-1-i)+j] += grid[i][j];
        }

    long long max_white = -1, max_black = -1;
    int wx, wy, bx, by;
    bool black = true;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            long long val = diag1[i+j] + diag2[(N-1-i)+j] - grid[i][j];;
            if(black && val > max_black){
                max_black = val;
                bx = i;
                by = j;
            }
            if(!black && val > max_white){
                max_white = val;
                wx = i;
                wy = j;
            }

            if(N%2) black = !black;
            else if(j != (N-1)) black = !black;
    }

    cout << max_white + max_black << endl;
    cout << bx+1 << " " << by+1 << " " << wx+1 << " " << wy+1 << endl;
    return 0;
}