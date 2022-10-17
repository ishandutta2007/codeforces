#include <iostream>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

// -1: can't put this
//  0: it's a zero
//  3: unfulfilled 1
//  4: fulfilled 1
//  2: it's a 2
//  5: it's a bomb
//  6: starting

int code(int prev, char cur){
    if(prev == 6){
        if(cur == '2') return -1;
        if(cur == '1') return 3;
        if(cur == '0') return 0;
        return 5;
    }
    
    if(cur == '0'){
        if(prev == 3 || prev == 5 || prev == 2) return -1;
        return 0;
    }
    else if(cur == '1'){
        if(prev == 5) return 4;
        if(prev == 2 || prev == 3) return -1;
        return 3;
    }
    else if(cur == '2'){
        if(prev != 5) return -1;
        return 2;
    }
    else{
        if(prev == 4 || prev == 0) return -1;
        return 5;
    }
}

string s;
int way[7][MAXN], ans;

void add(int &a, int b){ a = (a + b) % MOD; }

int main(){
    cin >> s;
    way[6][0] = 1;
    
    for(int i=1; i<=s.length(); i++){
        for(int p=0; p<7; p++){
            if(s[i-1] == '?'){
                for(char h='0'; h<='2'; h++){
                    int j = code(p, h);
                    if(j == -1) continue;
                    add(way[j][i], way[p][i-1]);
                }
                int j = code(p, '*');
                if(j != -1) add(way[j][i], way[p][i-1]);
            }
            else{
                int j = code(p, s[i-1]);
                if(j != -1) add(way[j][i], way[p][i-1]);
            }
        }
    }

    for(int e=0; e<6; e++)
        if(e!=2 && e!=3)
            add(ans, way[e][s.length()]);
    cout << ans << endl;
}