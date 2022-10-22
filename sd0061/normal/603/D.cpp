#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 2005;
const int Q = 1e9 + 7;

int n;
typedef pair<long double , long double> Point;
#define x first
#define y second
Point P[N];
const long double eps = 1e-12;
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int A , B , C;
        scanf("%d%d%d" , &A , &B , &C);
        int D = A * A + B * B;
        P[i].x = (long double) A * C / D;
        P[i].y = (long double) B * C / D;        
    }    
    LL res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        vector<long double> V;
        int flag = 0;
        for (int j = i + 1 ; j < n ; ++ j) {
            Point v(P[j].x - P[i].x , P[j].y - P[i].y);
            if (fabs(v.x) < eps && fabs(v.y) < eps) {
                flag = 1;
            } else if (fabs(v.x) < eps) {
                V.push_back(1e100);
            } else {
                V.push_back(v.y / v.x);
            }                
        }
        if (flag) res += V.size();
        sort(V.begin() , V.end());
        for (int j = 0 ; j < V.size() ; ++ j) {
            int k = j;
            while (k < V.size() && fabs(V[k] - V[j]) < eps)
                ++ k;
            res += (k - j) * (k - j - 1) / 2;
            j = k - 1;
        }        
    }
    cout << res << endl;
    return 0;
}