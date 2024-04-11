#include <iostream>
#include <string.h>
using namespace std;

int N, pow[8] = {1e7, 1e6, 1e5, 1e4, 1e3, 1e2, 1e1, 1e0};
int v[100005];
char g[100005][8];

void fill(int i, string v){
    for(int j=0; j<v.size(); j++)
        g[i][j + 8 - v.size()] = v[j];
}

bool fix(int i){
    int max = 0;
    for(int j=0; j<8; j++){
        int dig = (g[i][j]=='?')?9:(g[i][j]-'0');
        max = 10 * max + dig;
    }

    if(max <= v[i-1]) return false;

    bool f = true;
    for(int j=0; j<8; j++){
        if(g[i][j] == '?'){
            g[i][j] = '9';
            while((g[i][j]>('0'+f)) && (max - pow[j] > v[i-1])){
                g[i][j]--;
                max -= pow[j];
            }
        }
        if(g[i][j] > '0') f = false;        
    }

    v[i] = max;
    return true;
}

int main(){
    memset(g, '0', sizeof(g));

    cin >> N;
    for(int i=0; i<N; i++){
        string tmp; cin >> tmp;
        fill(i+1, tmp);
    }

    for(int i=1; i<=N; i++)
        if(!fix(i)){
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
    for(int i=1; i<=N; i++)
        cout << v[i] << "\n";
    cout.flush();
    return 0;
}