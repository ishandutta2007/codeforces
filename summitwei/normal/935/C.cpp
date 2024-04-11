#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;

double getDist(pdd loc1, pdd loc2){
    return sqrt(pow(loc1.first - loc2.first, 2) + pow(loc1.second - loc2.second, 2));
}

int main(){
    double R, x1, x2, y1, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    pdd flatCent = make_pair(x1, y1);
    pdd fafaCent = make_pair(x2, y2);

    if(getDist(flatCent, fafaCent) >= R){
        cout << x1 << " " << y1 << " " << R;
        return 0;
    }

    if(flatCent == fafaCent){
        cout << x1+R/2 << " " << y1 << " " << R/2;
        return 0;
    }


    double dist = getDist(flatCent, fafaCent);
    double distToFafa = (dist + R)/2;
    double distToCent = distToFafa - dist;

    double tempDist = dist - distToCent;

    double xCoor1 = (x1*tempDist + x2*distToCent)/(tempDist + distToCent);
    double yCoor1 = (y1*tempDist + y2*distToCent)/(tempDist + distToCent);

    double xCoor = 2 * x1 - xCoor1;
    double yCoor = 2 * y1 - yCoor1;

    //double xCoor = (x2*distToFafa - x1*distToCent)/(distToFafa+distToCent);
    //double yCoor = (y2*distToFafa - y1*distToCent)/(distToFafa+distToCent);

    cout << setprecision(10) << fixed << xCoor << " " << yCoor << " " << distToFafa;
    //cout << " " << xCoor1 << " " << yCoor1;



    return 0;
}