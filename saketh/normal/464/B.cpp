#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long ord[8][3];
long long dis[8];
int rat[7] = {1, 1, 1, 2, 2, 2, 3};

long long dist(int i, int j){
    long long ans = 0;
    for(int k=0; k<3; k++)
        ans += pow(ord[i][k] - ord[j][k], 2);
    return ans;
}

int tmp[3];
bool orth(int a, int b, int c, int d){
    tmp[0] = a;
    tmp[1] = b;
    tmp[2] = c;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++){
            if(i == j) continue;
            long long dp = 0;
            for(int k=0; k<3; k++)
                dp += (ord[tmp[i]][k] - ord[d][k]) * (ord[tmp[j]][k] - ord[d][k]);
            if(dp != 0) return false;
        }
    return true;
}

int d1[3], d2[3], d3[1];
bool check(){
    for(int p=0; p<8; p++){
        for(int q=0; q<8; q++)
            dis[q] = dist(p, q);
        sort(dis, dis+8);

        if(dis[1] == 0) return false;

        for(int i=0; i<7; i++)
            if(dis[i+1] / dis[1] != rat[i])
                return false;

        int i1 = 0, i2 = 0, i3 = 0;
        for(int q=0; q<8; q++){
            int rat = dist(p, q) / dis[1];
            if(rat == 1) d1[i1++] = q;
            else if(rat == 2) d2[i2++] = q;
            else if(rat == 3) d3[i3++] = q;
        }

        if(!orth(d1[0], d1[1], d1[2], p)) return false;
    }
    return true;
}

bool dfs(int d){
    if(d==8) return check();

    do{
        if(dfs(d+1)) return true;
    } while(next_permutation(ord[d], ord[d]+3));

    return false;
}

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<3; j++)
            cin >> ord[i][j];
        sort(ord[i], ord[i]+3);
    }

    if(dfs(0)){
        cout << "YES" << endl;
        for(int i=0; i<8; i++){
            for(int j=0; j<3; j++)
                cout << ord[i][j] << " ";
            cout << endl;
        }
    }
    else cout << "NO" << endl;
    return 0;
}