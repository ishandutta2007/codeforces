#include <iostream>
#include <cmath>
using namespace std;

double A, D;
int N;

pair<double, double> coord(double dist){
    double laps = floor(dist / (4 * A));
    dist -= 4 * A * laps;
    if(dist <= A) return make_pair(dist, 0);
    dist -= A;
    if(dist <= A) return make_pair(A, dist);
    dist -= A;
    if(dist <= A) return make_pair(A-dist, A);
    dist -= A;
    return make_pair(0, A-dist);
}

int main(){
    cin >> A >> D >> N;
    
    cout.precision(8);
    for(int n=1; n<=N; n++){
        pair<double, double> r = coord(n * D);
        cout << r.first << " " << r.second << "\n";
    }

    cout.flush();
    return 0;
}