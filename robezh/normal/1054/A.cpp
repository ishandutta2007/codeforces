#include <bits/stdc++.h>
using namespace std;

int x,y,z,t1,t2,t3;

int main(){
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int ele = abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3;
    int walk = abs(x - y) * t1;

//    cout << ele << " " << walk << endl;
    if(ele <= walk) cout << "YES" << endl;
    else cout << "NO";
}