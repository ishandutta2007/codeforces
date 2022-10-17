#include <iostream>
#include <cmath>
using namespace std;

typedef double db;
typedef pair<db, db> pt;

const db PI = 3.14159265358979323846;
db p[3][2], m[3][3];

db det(){
    db a = m[0][0] * (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    db b = m[0][1] * (m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    db c = m[0][2] * (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    return a - b + c;
}

db dist(pt a, pt b){
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

pt cent(){
    for(int i=0; i<3; i++){
        m[i][0] = p[i][0];
        m[i][1] = p[i][1];
        m[i][2] = 1.0;
    } db d = 2 * det();

    for(int i=0; i<3; i++){
        m[i][0] = pow(p[i][0], 2) + pow(p[i][1], 2);
        m[i][1] = p[i][1];
        m[i][2] = 1.0;
    } db h = det();

    for(int i=0; i<3; i++){
        swap(m[i][0], m[i][1]);
        m[i][0] = p[i][0];
    } db k = det();

    return make_pair(h/d, k/d);
}

int main(){
    cout.precision(20);
    
    for(int i=0; i<3; i++)
        cin >> p[i][0] >> p[i][1];

    pt ctr = cent();
    db rad = dist(ctr, make_pair(p[0][0], p[0][1]));

    for(int i=0; i<3; i++){
        p[i][0] -= ctr.first;
        p[i][1] -= ctr.second;
    }

    for(int N=3; N<=100; N++){
        bool good = true;

        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                double ang1 = atan2(p[i][1], p[i][0]);
                double ang2 = atan2(p[j][1], p[j][0]);
                good &= fabs(sin(N/2.0 * (ang1-ang2))) < 1e-3;
            }

        if(good){
            double ang = 2 * PI / N;
            cout << N * rad * rad * sin(ang) / 2.0 << endl;
            return 0;
        }
    }

    return 0;
}