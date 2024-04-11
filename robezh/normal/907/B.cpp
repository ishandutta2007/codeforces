#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

string c[11];
int cnt[3][3];

P get_part(int i, int j){
    P res;
    res.first = (i <= 2 ? 0 : (i <= 6 ? 1 : 2));
    res.second = (j <= 2 ? 0 : (j <= 6 ? 1 : 2));
    return res;
}

void add_cnt(int i, int j){
    P p = get_part(i,j);
    cnt[p.first][p.second] ++;
}

int main() {
    int a, b;
    for(int i = 0; i < 11; i++) getline(cin, c[i]);
    cin >> a >> b;
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < c[i].size(); j++){
            if(c[i][j] != ' ' && c[i][j] != '.'){
                add_cnt(i,j);
            }
        }
    }
    int pa = (a-1) % 3, pb = (b-1) % 3;
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < c[i].size(); j++){
                bool e = (get_part(i,j).first == pa) && (get_part(i,j).second == pb);
                if(cnt[pa][pb] == 9) cout << (c[i][j] == '.' ? '!' : c[i][j]);
                else cout << (c[i][j] == '.' && e? '!' : c[i][j]);
            }
            cout << endl;
        }
//    for(int i = 0; i < 3; i++){
//        printf("%d %d %d\n", cnt[i][0],cnt[i][1], cnt[i][2]);
//    }

}