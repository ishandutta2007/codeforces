#include <bits/stdc++.h>
using namespace std;

int n = 0;
int h;
int height[100050];
vector<int> ans;

int main() {
    scanf("%d", &h);
    for(int i = 0; i <= h; i ++){scanf("%d", &height[i]); n += height[i];}

    bool good = true;
    int se;
    for(int i = 0; i < h; i++){
        if(height[i] != 1 && height[i+1] != 1){
            se = i;
            good = false; break;
        }
    }
    if(good) return !printf("perfect");

    int ver, to;
    int prev = 0;
    int pos = 0;
    while(pos <= h){
        for(int i = 0; i < height[pos]; i++){
            ans.push_back(prev);
        }
        prev = ans.size();
        if(pos == se){
            ver = ans.size() + 1;
            to = ans.size() - 1;
        }
        pos++;
    }
    cout << "ambiguous" << endl;
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
    ans[ver] = to;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;


}