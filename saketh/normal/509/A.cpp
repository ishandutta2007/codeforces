#include <iostream>
using namespace std;

int N;
int vals[12][12];

int main(){
    cin >> N;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(i==0 || j==0) vals[i][j] = 1;
            else vals[i][j] = vals[i-1][j] + vals[i][j-1];
        }

    cout << vals[N-1][N-1] << endl;
}