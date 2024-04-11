#include <iostream>
using namespace std;

int N;
char grid[105][105];

int main(){
    cin >> N;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> grid[i][j];

    bool okay = true;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            okay &= ! ((grid[i-1][j]=='o')
                      ^(grid[i+1][j]=='o')
                      ^(grid[i][j-1]=='o')
                      ^(grid[i][j+1]=='o'));

    cout << ((okay)?"YES":"NO") << endl;
    return 0;
}