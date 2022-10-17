#include <iostream>
using namespace std;

int N, K;
double earn[2][2000];
double coin[2000];
double upg[2000];
double drop[2000];

int main(){
    cin >> N >> K;
    double no_sel = (K - 1.0) / K;
    double sel = 1.0 / K;

    for(int w=1; w<2000; w++){
        upg[w] = 1.0 / (w + 1.0);
        coin[w] = w / (w + 1.0);
        drop[w] = (w + 1.0) / 2.0;
    }

    for(int i=1; i<=N; i++){
        int curr = i%2, prev = (i-1)%2;
        for(int w=1; w<2000; w++){
            earn[curr][w] = no_sel * earn[prev][w];
            double sel_exp = coin[w] * (drop[w] + earn[prev][w]);
            if(w < 1999) sel_exp += upg[w] * (w + earn[prev][w+1]);
            earn[curr][w] += sel * sel_exp;
        }
    }

    cout.precision(20);
    cout << earn[N%2][1] * K << endl;
    return 0;
}