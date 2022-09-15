#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    cout<<fixed;
    cout.precision(20);
    while (t--)
        solve();
    return 0;
}
class Point{
public:
    double x,y;
    Point(double x, double y):x(x), y(y){}
    Point operator - (const Point& b){
        return Point(x - b.x, y - b.y);
    }
    Point operator + (const Point& b){
        return Point(x + b.x, y + b.y);
    }
    void print(){
        cout<<x<<' '<<y<<'\n';
    }
    Point operator * (double d){
        return Point(x*d,y*d);
    }
};
 
Point points[] = {Point(3.830127018922193,3.366025403784439),
Point(-3.601321235851749, 10.057331467373021),
Point(0.466045194906253, 19.192786043799030),
Point(10.411264148588986, 18.147501411122495),
Point(12.490381056766580 ,8.366025403784439)};
void solve(){ 
    int k;
    cin>>k;
    
    cout<<4 * k + 1<<endl;
    
    points[0].print();
    
    for(int i = 0;i < k;++i){
        Point add = (points[2] - points[0])*i;
        for(int j = 1; j < 5;++j){
            (points[j] + add).print();
        }
    }
    
    for(int n= 0;n<k;++n){
        cout<<abs(4 * n - 1)<<' '<<4 * n + 2<<' '<<4*n+3<<' '<<4*n + 4<<' '<<4*n + 5<<endl;
    }
    
    for(int n = k ; n >= 0; --n){
        cout<<abs(4 * n - 1)<<' ';
    }
    
    for(int n = 0; n<k;++n){
        cout<<(4*n+4)<<' '<<(4*n+2)<<' '<<(4*n + 5)<<' '<<(4*n + 3)<<' ';
    }
    
    
    
}