#include <bits/stdc++.h>
using namespace std;

int w,l;
int num[100050], cur[100050];
map<int, int> mp;
vector<int> todel;

int main(){
    scanf("%d%d", &w, &l);
    cur[0] = (int)2e9;
    num[w] = (int)2e9;
    for(int i = 1; i < w; i++){
        scanf("%d", &num[i]);
    }
    int las = 0;
    for(int i = 1; i <= w; i++){
        las = max(las, i-l);
        while(num[i] > 0 && las != i){
            int mov = min(cur[las], num[i]);
            num[i] -= mov;
            cur[i] += mov;
            cur[las] -= mov;
            if(cur[las] == 0) las++;
        }
    }
    cout << cur[w];
}