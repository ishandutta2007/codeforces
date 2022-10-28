#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

long long dp[205][205][205];
int hy,ay,dy,hm,am,dm;

bool wins(int x,int y,int z,int hm,int am,int dm){
    if(y<=dm)
        return false;
    double d = 1;
    int rounds = ceil(hm/(d*(y-dm)));
    int xhp = x - rounds*max(0,am-z);
    if(xhp > 0)
        return true;
    return false;
}

int find(int att,int def){
    if(att <= dm)
        return -1;
    double d = 1;
    int rounds = ceil(hm/(d*(att-dm)));
    int hploss = rounds*(max(0,am-def));
    int finalhp = hy - hploss;
    if(finalhp > 0)
        return 0;
    else
        return 1-finalhp;
}

int main(){ sl
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    int h,a,d;
    cin >> h >> a >> d;

    int ans = 1e9;

    for(int x=ay;x<=200;x++){
        for(int y=dy;y<=100;y++){
            int hpneeded = find(x,y);
            if(hpneeded != -1)
                ans = min(ans,hpneeded*h + a*(x-ay) + d*(y-dy));
        }
    }

    cout<<ans;
    return 0 ;
}