#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int ax, ay, bx, by, fx, fy;
        cin >> ax >> ay >> bx >> by >> fx >> fy;

        int ans = abs(ax - bx) + abs(ay - by);
        if(ax > bx) swap(ax, bx), swap(ay, by);
        if(ay == by && fy == ay && ax <= fx && fx <= bx)
            ans += 2;
        else{
            if(ay > by) swap(ay, by), swap(ax, bx);
            if(ax == bx && fx == ax && ay <= fy && fy <= by)
                ans += 2;
        }
        cout << ans << "\n";
    }
}