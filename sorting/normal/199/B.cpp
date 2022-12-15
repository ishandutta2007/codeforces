#include <bits/stdc++.h>

using namespace std;

struct circle{
    int x, y, r;
};

circle c[4];

bool intersect(circle a, circle b1, circle b2){
    int d = (a.x - b1.x) * (a.x - b1.x) + (a.y - b1.y) * (a.y - b1.y);
    if((b2.r <= a.r && d <= (a.r - b2.r) * (a.r - b2.r)) || (b1.r >= a.r && d <= (a.r - b1.r) * (a.r - b1.r)) || (d >= (a.r + b2.r) * (a.r + b2.r))){
        //cout << "yeah" << endl;
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c[0].x >> c[0].y >> c[0].r >> c[1].r;
    c[1].x = c[0].x;
    c[1].y = c[0].y;

    cin >> c[2].x >> c[2].y >> c[2].r >> c[3].r;
    c[3].x = c[2].x;
    c[3].y = c[2].y;


    int answer = 0;
    for(int i = 0; i < 4; ++i){
        bool ok = true;
        if(i == 0 || i == 1)
            ok = !intersect(c[i], c[2], c[3]);
        else
            ok = !intersect(c[i], c[0], c[1]);
        answer += ok;
    }

    cout << answer << "\n";
}