#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int M = 1e9 + 7;

struct Point {
    int x, y, z;
    int ind;
    
    Point() {};
};

bool operator < (Point& p1, Point& p2) {
    if(p1.x != p2.x)
        return p1.x < p2.x;
    else if(p1.y != p2.y)
        return p1.y < p2.y;
    else
        return p1.z < p2.z;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].ind = i;
    }
    
    vector<bool> b(n, false);
    for(int i = 0; i < n; i++)
        if(!b[i]) {
            b[i] = true;
            long double mn = 1e18;
            int l = n;
            for(int j = i + 1; j < n; j++) {
                if(!b[j]) {
                    long double dx = a[i].x - a[j].x, 
                                dy = a[i].y - a[j].y,
                                dz = a[i].z - a[j].z;
                    long double cur = dx * dx + dy * dy + dz * dz;
                    
                    if(cur < mn) {
                        mn = cur;
                        l = j;
                    }
                }
            }
            
            b[l] = true;
            
            cout << i + 1 << ' ' << l + 1 << endl;
        }
    
    //map<map<>>
    
    /*sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i += 2) {
        cout << a[i].ind + 1 << ' ' << a[i + 1].ind + 1 << endl;
    }*/
 }