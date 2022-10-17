#include <iostream>
#include <algorithm>
using namespace std;

struct env{
    int w, h, idx;
    bool operator<(const env &y) const{
        return w < y.w;
    }
};

int N, W, H, B, I=-1;
int ans[5005], prv[5005];
env all[5005];

void print(int i){
    if(ans[i] != 1) print(prv[i]);
    cout << all[i].idx+1 << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> W >> H;
    for(int i=0; i<N; i++){
        cin >> all[i].w >> all[i].h;
        all[i].idx = i;
    }
     
    sort(all, all+N);

    for(int i=0; i<N; i++){
        if(all[i].w <= W || all[i].h <= H) continue;
        ans[i] = 1;
        for(int j=0; j<i; j++){
            if(all[j].w >= all[i].w || all[j].h >= all[i].h) continue;
            if(1+ans[j] > ans[i]){
                ans[i] = 1 + ans[j];
                prv[i] = j;
            } 
        }

        if(ans[i] > B){
            B = ans[i];
            I = i;
        }
    }

    if(I == -1){ cout << 0 << endl; return 0; }
    cout << B << endl;
    print(I);
    cout << endl;
    return 0;
}