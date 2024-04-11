#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long N, m[4][4], p[4][2];

long long hypot(long long dx1, long long dy1){
    return dx1 * dx1 + dy1 * dy1;
}

bool square(){
    vector<long long> dist;

    for(long long i=0; i<4; i++)
        for(long long j=i+1; j<4; j++)
            dist.push_back(hypot(p[i][0] - p[j][0],
                                  p[i][1] - p[j][1]));

    sort(dist.begin(), dist.end());

    if(dist[5] != dist[4]) return false;
    
    for(long long j=1; j<4; j++)
        if(dist[0] != dist[j]) return false;
    
    if(!dist.front()) return false;
    
    return 2*dist.front() == dist.back();
}

pair<long long, long long> rot(long long x, long long y, long long hx, long long hy, long long times){
    if(times == 0) return make_pair(x, y);
    
    long long dx = x - hx;
    long long dy = y - hy;
    
    return rot(hx - dy, hy + dx, hx, hy, times-1);
}

long long ans(){
    long long ans = 999;

    for(long long lw=0; lw<4*4*4*4; lw++){
        long long moves = 0, w = lw;
        for(long long i=0; i<4; i++){
            pair<long long, long long> pt = rot(m[i][0], m[i][1], m[i][2], m[i][3], w%4);
            p[i][0] = pt.first;
            p[i][1] = pt.second;
        
            moves += w%4;
            w/=4;
        }
        if(square()){
            ans = min(ans, moves);
        }
    }

    return (ans == 999)?-1:ans;
}

int main(){
    cin >> N;

    for(long long i=0; i<N; i++){
        for(long long j=0; j<4; j++)
            for(long long k=0; k<4; k++)
                cin >> m[j][k];
        cout << ans() << endl;
    }

    return 0;
}