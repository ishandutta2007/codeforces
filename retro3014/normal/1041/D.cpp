#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

struct S{
    int x, y;
};

int N, H;

S tmp;

vector<S> v;
int f=0, b=0;
int ans=0;
int len=0;
int d=0;

int main(){
    scanf("%d%d", &N, &H);
    for(int i=0; i<N; i++){
        scanf("%d %d", &tmp.x, &tmp.y); v.push_back(tmp);
    }
    //sort(v.begin(), v.end());
    for(int i=0; i<N; i++){
        if(i==0){
            d=H;
            len=v[i].y-v[i].x;
        }
        else{
            d+=v[i].x-v[i-1].y;
            len-=v[i].x-v[i-1].x;
        }
        while(b<N-1 && d>v[b+1].x-v[b].y){
            d-=v[b+1].x-v[b].y;
            len+=v[b+1].y-v[b].y;
            b++;
        }
        //rintf("%d %d %d\n", i, len, d);
        ans=max(ans, len+d);
    }
    printf("%d", ans);
    
    return 0;
}