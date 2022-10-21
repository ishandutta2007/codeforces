#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld PI = 3.1415926535897;
typedef pair<ld, ld> P;

int n;
ld a[4],b[4],x[4],y[4];
ld xt[4][4], yt[4][4];
int tim[4];
ld EPS = 1e-6;

ld dis(P p1, P p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

bool check(){
    P p[4];
    for(int i = 0; i < 4; i++){
        p[i].first = xt[tim[i]][i];
        p[i].second = yt[tim[i]][i];
    }
    sort(p, p+4);
    do{
        bool flag = true;
        for(int i = 0; i < 4; i++){
            if(fabs(dis(p[i], p[(i+1)%4]) - dis(p[(i+1)%4], p[(i+2)%4])) > EPS || fabs(dis(p[i], p[(i+1)%4])) < EPS){
                flag = false;
                break;
            }
        }
        flag &= (fabs(dis(p[0], p[2]) - dis(p[1], p[3])) < EPS && fabs(dis(p[1], p[3])) > EPS);
        if(flag){
            return true;
        }
    }while(next_permutation(p, p+4));

    return false;
}

int main(){
    cin >> n;
    while(n--){
        for(int i = 0; i < 4; i++) cin >> x[i] >> y[i] >> a[i] >> b[i];
        for(int i = 0; i < 4; i++){
            for(int t = 0; t < 4; t++){
                xt[t][i] = (x[i]-a[i]) * cos(PI/2 * t) - (y[i]-b[i]) * sin(PI/2 * t) + a[i];
                yt[t][i] = (x[i]-a[i]) * sin(PI/2 * t) + (y[i]-b[i]) * cos(PI/2 * t) + b[i];
            }
        }

        int res = 1000;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    for(int t = 0; t < 4; t++){
                        tim[0] = i, tim[1] = j;
                        tim[2] = k, tim[3] = t;
                        if(check()){
                            res = min(res, i+j+k+t);
                        }
                    }
                }
            }
        }
        cout << (res == 1000 ? -1 : res) << endl;
    }
    
}