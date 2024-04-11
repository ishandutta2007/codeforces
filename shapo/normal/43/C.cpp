#include <iostream>
#include <vector>
#include <cmath>
#define maxn 10000;

using namespace std;

typedef vector< int > vi;

int main(){
    int n;
    int cur[3] = {0, 0, 0};
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        cur[a % 3]++;
    }
    cout <<(cur[0] / 2 + min(cur[1], cur[2])) << endl;
}