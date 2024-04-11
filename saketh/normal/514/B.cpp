#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 1005;

int N, OX, OY;
int SX[MAXN], SY[MAXN];
set<pair<int, int> > all;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> OX >> OY;

    for(int i=0; i<N; i++){
        cin >> SX[i] >> SY[i];
        
        SX[i] -= OX;
        SY[i] -= OY;

        if(SY[i] < 0){
            SY[i] *= -1;
            SX[i] *= -1;
        }

        int g = gcd(SX[i], SY[i]);
        SX[i] /= g;
        SY[i] /= g;

        all.insert(make_pair(SX[i], SY[i]));
    }

    cout << all.size() << endl;
}