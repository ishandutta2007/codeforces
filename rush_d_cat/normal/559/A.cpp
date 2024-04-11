#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double a1, a2, a3, a4, a5, a6;
vector< pair<double, double> > vec;
int main() {
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    double x = 0, y = 0;
    vec.push_back( make_pair(x, y) );

    x += a1; 
    vec.push_back( make_pair(x, y) );
    
    x += a2 / 2; y += a2 * sqrt(3) / 2;
    vec.push_back( make_pair(x, y) );

    x -= a3 / 2; y += a3 * sqrt(3) / 2;
    vec.push_back( make_pair(x, y) );

    x -= a4;
    vec.push_back( make_pair(x, y) );

    x -= a5 / 2; y -= a5 * sqrt(3) / 2;
    vec.push_back( make_pair(x, y) );

    double area = 0;
    for (int i = 0; i < vec.size() - 1; i ++) {
        area += vec[i].first * vec[i+1].second - vec[i].second * vec[i+1].first;
    }
    area *= 2;
    double ans = area / sqrt(3);
    printf("%d\n", (int)(ans + 0.5) );
}