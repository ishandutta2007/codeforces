#include <bits/stdc++.h>
using namespace std;

bool black(int x){
    cout << x << " " << x << endl;
    fflush(stdout);
    string str;
    cin >> str;
    return str == "black";
}

int n;
bool bd;

int main(){
    cin >> n;
    int l = 0, r = (int)1e9, mid;
    bd = black(0);
    for(int i = 0; i < n-1; i++){
        mid = (l + r) / 2;
        if(black(mid) ^ (!bd)) l = mid;
        else r = mid;
    }
    cout << r << " " << l << " " << l << " " << r << endl;
    fflush(stdout);
}