#include <iostream>

using namespace std;

int main() {
    int n, m;
    char a;
    cin >> n >> m;
    int minx = 200;
    int miny = 200;
    int maxx = -1;
    int maxy = -1;
    int d;
    int size = 0;
    int bnum = 0;

    
    for (int i = 0; i < n*m; i++){
        cin >> a;
        if (a == 'B'){
            d = i % m;
            maxx = max(maxx, d);
            minx = min(minx, d);
            maxy = max(maxy, i/m);
            miny = min(miny, i/m);
            bnum++;
        }
        size = max(maxx-minx+1, maxy-miny+1);
        
    }
    if(bnum == 0){
        cout << 1;
    }
    else if(size > m || size > n){
            cout << -1;
        }
        else{
            cout << size*size - bnum;
        }
    
}