#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> v[20005];
    for(int i = 1; i <= 20000; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                v[i].push_back(j);
                if(j * j != i) v[i].push_back(i / j);
            }
        }
    }
    for(int w = 0; w < t; w++){
        int a, b, c;
        cin >> a >> b >> c;
        int aa = 1, ab = 1, ac = 1;
        for(int y = 1; y <= 20000; y++){
            int lx = 1;
            for(int x : v[y]){
                if(abs(a - x) < abs(a - lx)) lx = x;
            }
            int z;
            if(c <= y) z = y;
            else{
                if(c % y <= y - c % y) z = y * (c / y);
                else z = y * (c / y + 1);
            }
            if(abs(a - lx) + abs(b - y) + abs(c - z) < abs(a - aa) + abs(b - ab) + abs(c - ac)){
                aa = lx, ab = y, ac = z;
            }
        }
        cout << abs(a - aa) + abs(b - ab) + abs(c - ac) << endl;
        cout << aa << " " << ab << " " << ac << endl;
    }
}