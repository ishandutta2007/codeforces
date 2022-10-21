#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

int n;
double vb,vs;
double cor[105];
double x,y;

int main(){
    cin >> n >> vb >> vs;
    for(int i = 0; i < n; i++) cin >> cor[i];
    cin >> x >> y;

    double time = 0;
    double mintime = INF;
    int index;
    for(int i = 1; i < n; i++){
        time += (cor[i]-cor[i-1])/vb;
        if(time + hypot(x-cor[i], y) / vs < mintime){
            mintime = time + hypot(x-cor[i], y) / vs;
            index = i;
        }
        else if(time + hypot(x-cor[i], y) / vs == mintime){
            if(hypot(x-cor[i], y) < hypot(x-cor[index], y)) index = i;
        }
    }
    cout << index + 1;
}