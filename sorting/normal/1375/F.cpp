#include <bits/stdc++.h>

using namespace std;

long long a[3];
long long p[3] = {0, 1, 2};
int w;
long long y;

void solve_12(){
    if(p[0] == w)
        y = a[p[2]] - a[p[1]];
    else
        y = a[p[2]] - a[p[0]];

    cout << y << "\n";
    fflush(stdout);
}

int main(){
    for(auto &x: a)
        cin >> x;

    
    sort(p, p + 3, [&](auto l, auto r){
        return a[l] < a[r];
    }); 

    cout << "First\n";
    fflush(stdout);

    y = 2 * a[p[2]] - a[p[1]] - a[p[0]];
    cout << y << "\n";
    fflush(stdout);

    cin >> w;
    w--;

    if(p[2] == w){
        a[w] += y;
        sort(p, p + 3, [&](auto l, auto r){
            return a[l] < a[r];
        });

        y = 2 * a[p[2]] - a[p[1]] - a[p[0]];
        cout << y << "\n";
        fflush(stdout);

        cin >> w;
        w--; 
    }

    solve_12();
    cin >> w;
}