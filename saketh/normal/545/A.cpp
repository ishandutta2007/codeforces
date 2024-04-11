#include <iostream>
#include <vector>
using namespace std;

int N;

bool flip[105];
int g[105][105];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> g[i][j];
            if(g[i][j] < 1) continue;
            if(g[i][j] & 1) flip[i] = true;
            if(g[i][j] & 2) flip[j] = true;
        }

    vector<int> res;
    for(int i=0; i<N; i++)
        if(!flip[i])
            res.push_back(i+1);

    cout << res.size() << endl;
    for(int x : res)
        cout << x << " ";
    cout << endl;
}