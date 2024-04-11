#include <iostream>
#include <set>
using namespace std;

int N; char g[305][305];
set<char> a, b;

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> g[i][j];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(i==j || (i+j == N-1))
                a.insert(g[i][j]);
            else b.insert(g[i][j]);
        }

    if((a.size() == 1) && (b.size() == 1) && (*a.begin() != *b.begin()))
        cout << "YES" << endl;
    else cout << "NO" << endl;
}