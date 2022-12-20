#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 110;

vector<pii> posib1, posib2, posib3;

bool chosen[maxn][maxn];

void add(pii p , int c){
    chosen[p.first][p.second] = true;
    cout << c << " " << p.first+1 << " " << p.second+1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j) & 1)
                posib1.push_back({i, j});
            else
                posib2.push_back({i, j});
        }
    }
    while(sz(posib1) && sz(posib2)){
        int c;
        cin >> c;
        if(c != 1){
            pii p = posib1.back();
            posib1.pop_back();
            add(p, 1);            
        }
        else{
            pii p = posib2.back();
            posib2.pop_back();
            add(p, 2);            
        }
    }
    int used = 1;
    if(posib2.empty()){
        used = 2;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!chosen[i][j])
                posib3.push_back({i, j});
        }
    }
    while(sz(posib3)){
        int c;
        cin >> c;
        pii p = posib3.back();
        posib3.pop_back();
        if(c != 1 && used != 1)
            add(p, 1);
        else if(c != 2 && used != 2)
            add(p, 2);
        else if(c != 3 && used != 3)
            add(p, 3);
    }
    return 0;
}