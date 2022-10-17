#include <iostream>
#include <algorithm>
using namespace std;

int N;
string s, p[1024];

int main(){
    cin >> N >> s;
    for(int i=0; i<N; i++){
        p[i] = s.substr(i) + s.substr(0, i);
        int ld = p[i][0] - '0';

        for(int j=0; j<N; j++){
            p[i][j] -= ld;
            if(p[i][j] < '0') p[i][j] += 10;
        }
    }

    sort(p, p+N);
    cout << p[0] << endl;
}