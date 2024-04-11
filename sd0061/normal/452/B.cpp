#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 1005;
typedef pair<int , int> Point;
#define X first
#define Y second

int n , m;
double dis(Point A , Point B) {
    return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}

void work() {
    int i , j , k , l;
    scanf("%d%d",&n,&m);
    vector<Point> V;
    for (i = 0 ; i <= 4 ; ++ i)
        for (j = 0 ; j <= i ; ++ j)
            if (j <= n && i - j <= m)
                V.push_back(Point(j , i - j));
    for (i = 0 ; i <= 4 ; ++ i)
        for (j = 0 ; j <= i ; ++ j)
            if (n - j >= 0 && m - (i - j) >= 0)
                V.push_back(Point(n - j , m - (i - j)));
    sort(V.begin() , V.end());
    V.erase(unique(V.begin() , V.end()) , V.end());
    double res = 0;
    int I , J , K , L;
    for (i = 0 ; i < V.size() ; ++ i)
        for (j = 0 ; j < V.size() ; ++ j) if (i != j)
            for (k = 0 ; k < V.size() ; ++ k) if (i != k && k != j)
                for (l = 0 ; l < V.size() ; ++ l) if (l != i && l != j && l != k){
                    double len = dis(V[i] , V[j]) + dis(V[j] , V[k]) + dis(V[k] , V[l]);
                    if (len > res)
                        I = i , J = j , K = k , L = l , res = len;
                }
    printf("%d %d\n" , V[I].X , V[I].Y);
    printf("%d %d\n" , V[J].X , V[J].Y);
    printf("%d %d\n" , V[K].X , V[K].Y);
    printf("%d %d\n" , V[L].X , V[L].Y);
}

int main(){
    work();
    return 0;
}