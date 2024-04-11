#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
typedef vector<vector<set<int>>> vvsi;
typedef vector<vector<set<pair<long long, long long>>>> vvspll;
typedef pair<long long, long long> pll;
typedef pair<long long, pair<long long, long long>> trip;
#define INF 100000000
#define MOD 257

int mod(int a, int b){
    return ((a % b) + b) % b;
}

struct Point{
    int x;
    int y;
};

bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;

    return (val > 0)? 1: 2;
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4) return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

int main(){
    vector<Point> square1(5); //0=4 cuz lazy
    vector<Point> square2(5);

    for(int i=0; i<4; i++){
        cin >> square1[i].x >> square1[i].y;
    }
    square1[4] = square1[0];
    for(int i=0; i<4; i++){
        cin >> square2[i].x >> square2[i].y;
    }
    square2[4] = square2[0];

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(doIntersect(square1[i], square1[i+1], square2[j], square2[j+1])){
                cout << "YES";
                return 0;
            }
        }
    }

    if(orientation(square2[0], square1[0], square1[1]) == orientation(square2[0], square1[1], square1[2]) && orientation(square2[0], square1[0], square1[1]) == orientation(square2[0], square1[2], square1[3]) && orientation(square2[0], square1[0], square1[1]) == orientation(square2[0], square1[3], square1[4])){
        cout << "YES";
    } else if(orientation(square1[0], square2[0], square2[1]) == orientation(square1[0], square2[1], square2[2]) && orientation(square1[0], square2[0], square2[1]) == orientation(square1[0], square2[2], square2[3]) && orientation(square1[0], square2[0], square2[1]) == orientation(square1[0], square2[3], square2[4])) {
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}