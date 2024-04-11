#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int ch[250];

int now(int x, int y){
    if(x == y) return 0;
    return (x > y ? 1 : -1);
}

int main(){
    ch['U'] = 2, ch['D'] = 3, ch['R'] = 0, ch['L'] = 1;
    cin >> n;
    getchar();
    getline(cin, str);
    int cnt = 0;
    int x = 0, y = 0;
    int pre = 0;
    for(int i = 0; i < str.length(); i++){
        x += dx[ch[str[i]]], y += dy[ch[str[i]]];
        if(now(x, y) != 0){
            if(pre == 0){
                pre = now(x, y);
            }
            else if(pre != now(x, y)){
                pre = now(x, y);
                cnt ++;
            }
        }
    }
    cout << cnt;

}