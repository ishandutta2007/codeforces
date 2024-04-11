#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

ll cor[8][3];
int total = (int)pow(6, 7);
int now[8];

ll get_dis(int i, int j){
    ll res = 0;
    for(int k = 0; k < 3; k++)
        res += (cor[i][k] - cor[j][k]) * (cor[i][k] - cor[j][k]);
    return res;
}

bool check_single(int i){
    map<ll, int> mp;
    for(int j = 0; j < 8; j++){
        if(i != j){
            mp[get_dis(i,j)]++;
        }
    }
    vector<ll> c1, c3;
    for(P p : mp){
        if(p.second == 1) c1.push_back(p.first);
        else if(p.second == 3) c3.push_back(p.first);
        else return false;
    }
    if(c3.size() != 2 || c1.size() != 1) return false;

    ll mid = max(c3[0], c3[1]), sma = min(c3[0], c3[1]);
    ll lar = c1[0];

    if((lar == sma*3) && (mid == sma * 2)) return true;
    return false;
}

bool check(){
    for(int i = 0; i < 8; i++) if(!check_single(i)) return false;
    return true;
}

int main(){
    for(int i = 0; i < 8; i++) for(int j = 0; j < 3; j++) cin >> cor[i][j];
    fill(now, now+8, 0);
    for(int i = 0; i < 8; i++) sort(cor[i], cor[i]+3);
    //int cnt = 0;
    for(int i = 0; i < total; i++){
        if(check()){
            printf("YES\n");
            for(int t = 0; t < 8; t++){
                for(int j = 0; j < 3; j++) cout << cor[t][j] << " ";
                cout << endl;
            }
            return 0;
        }

        int pos = 0;
        while(true){
            next_permutation(cor[pos], cor[pos]+3);
            now[pos]++;
            if(now[pos] == 6){now[pos++] = 0;}
            else break;
        }
    }
    return !printf("NO");

}